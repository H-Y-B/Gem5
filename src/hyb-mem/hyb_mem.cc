
#include "hyb-mem/hyb_mem.hh"

#include "debug/HybMem.hh"

HybMem::HybMem(HybMemParams *params) :
    SimObject(params),
    instPort(params->name + ".inst_port", this),
    dataPort(params->name + ".data_port", this),
    memPort(params->name + ".mem_side", this),
    blocked(false)
{
}

Port &
HybMem::getPort(const std::string &if_name, PortID idx)
{
    panic_if(idx != InvalidPortID, "This object doesn't support vector ports");

    // This is the name from the Python SimObject declaration (SimpleMemobj.py)
    if (if_name == "mem_side") {
        return memPort;
    } else if (if_name == "inst_port") {
        return instPort;
    } else if (if_name == "data_port") {
        return dataPort;
    } else {
        // pass it along to our super class
        return SimObject::getPort(if_name, idx);
    }
}

void
HybMem::CPUSidePort::sendPacket(PacketPtr pkt)//CPUSidePort<-[sendPacket]<-handleResponse<-recvTimingResp<-MemSidePort
{
    // Note: This flow control is very simple since the memobj is blocking.

    panic_if(blockedPacket != nullptr, "Should never try to send if blocked!");

    // If we can't send the packet across the port, store it for later.
    if (!sendTimingResp(pkt)) {//不能向CPU发送pkt，将pkt保存到blockedPacket中
        blockedPacket = pkt;
    }
}

AddrRangeList
HybMem::CPUSidePort::getAddrRanges() const//CPUSidePort::getAddrRanges()->HybMem::getAddrRanges()->memPort.getAddrRanges();
{
    return owner->getAddrRanges();
}

void
HybMem::CPUSidePort::trySendRetry()
{
    if (needRetry && blockedPacket == nullptr) {
        // Only send a retry if the port is now completely free
        needRetry = false;
        DPRINTF(HybMem, "Sending retry req for %d\n", id);
        sendRetryReq();
    }
}

void
HybMem::CPUSidePort::recvFunctional(PacketPtr pkt)//CPUSidePort::recvFunctional->HybMem::handleFunctional->
{
    // Just forward to the memobj.
    return owner->handleFunctional(pkt);
}

bool
HybMem::CPUSidePort::recvTimingReq(PacketPtr pkt)//CPU->CPUSidePort::recvTimingReq->handleRequest->[MemSidePort::sendPacket]->MEM
{
    // Just forward to the memobj.
    if (!owner->handleRequest(pkt)) {//HybMem是否在处理请求，不能再接受新的请求？
        needRetry = true;//需要再次发送请求给HybMem
        return false;
    } else {
        return true;
    }
}

void
HybMem::CPUSidePort::recvRespRetry()//再次向CPU发送pkt
{
    // We should have a blocked packet if this function is called.
    assert(blockedPacket != nullptr);

    // Grab the blocked packet.
    PacketPtr pkt = blockedPacket;
    blockedPacket = nullptr;

    // Try to resend it. It's possible that it fails again.
    sendPacket(pkt);
}

void
HybMem::MemSidePort::sendPacket(PacketPtr pkt)//CPU->CPUSidePort::recvTimingReq->handleRequest->[MemSidePort::sendPacket]->MEM
{
    // Note: This flow control is very simple since the memobj is blocking.

    panic_if(blockedPacket != nullptr, "Should never try to send if blocked!");

    // If we can't send the packet across the port, store it for later.
    if (!sendTimingReq(pkt)) {//不能向MEM发送pkt，将pkt保存到blockedPacket中
        blockedPacket = pkt;
    }
}

bool
HybMem::MemSidePort::recvTimingResp(PacketPtr pkt)//CPUSidePort<-sendPacket<-handleResponse<-[recvTimingResp]<-MemSidePort
{
    // Just forward to the memobj.
    return owner->handleResponse(pkt);
}

void
HybMem::MemSidePort::recvReqRetry()//再次向MEM发送pkt
{
    // We should have a blocked packet if this function is called.
    assert(blockedPacket != nullptr);

    // Grab the blocked packet.
    PacketPtr pkt = blockedPacket;
    blockedPacket = nullptr;

    // Try to resend it. It's possible that it fails again.
    sendPacket(pkt);
}

void
HybMem::MemSidePort::recvRangeChange()//CPUSidePort::sendRangeChange <-HybMem::sendRangeChange()<-MemSidePort::recvRangeChange()
{
    owner->sendRangeChange();
}

bool
HybMem::handleRequest(PacketPtr pkt)//CPU->CPUSidePort::recvTimingReq->[HybMem::handleRequest]->MemSidePort::sendPacket->MEM
{
    if (blocked) {//现在是否在处理请求
        // There is currently an outstanding request. Stall.
        return false;
    }

    DPRINTF(HybMem, "Got request for addr %#x\n", pkt->getAddr());

    // This memobj is now blocked waiting for the response to this packet.
    blocked = true;

    // Simply forward to the memory port
    memPort.sendPacket(pkt);

    return true;
}

bool
HybMem::handleResponse(PacketPtr pkt)//CPUSidePort<-sendPacket<-[handleResponse]<-recvTimingResp<-MemSidePort
{
    assert(blocked);
    DPRINTF(HybMem, "Got response for addr %#x\n", pkt->getAddr());

    // The packet is now done. We're about to put it in the port, no need for
    // this object to continue to stall.
    // We need to free the resource before sending the packet in case the CPU
    // tries to send another request immediately (e.g., in the same callchain).
    blocked = false;

    // Simply forward to the memory port
    if (pkt->req->isInstFetch()) {
        instPort.sendPacket(pkt);
    } else {
        dataPort.sendPacket(pkt);
    }

    // For each of the cpu ports, if it needs to send a retry, it should do it
    // now since this memory object may be unblocked now.
    instPort.trySendRetry();
    dataPort.trySendRetry();

    return true;
}

void
HybMem::handleFunctional(PacketPtr pkt)//CPUSidePort::recvFunctional->HybMem::handleFunctional->
{
    // Just pass this on to the memory side to handle for now.
    memPort.sendFunctional(pkt);
}

AddrRangeList
HybMem::getAddrRanges() const//CPUSidePort::getAddrRanges()->HybMem::getAddrRanges()->memPort.getAddrRanges();
{
    DPRINTF(HybMem, "Sending new ranges\n");
    // Just use the same ranges as whatever is on the memory side.
    return memPort.getAddrRanges();
}

void
HybMem::sendRangeChange()//CPUSidePort::sendRangeChange <-HybMem::sendRangeChange()<-MemSidePort::recvRangeChange()
{
    instPort.sendRangeChange();
    dataPort.sendRangeChange();
}



HybMem*
HybMemParams::create()
{
    return new HybMem(this);
}
