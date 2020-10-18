
#ifndef __HYB_MEM_HH__
#define __HYB_MEM_HH__

#include "mem/port.hh"
#include "params/HybMem.hh"
#include "sim/sim_object.hh"

/**
 * A very simple memory object. Current implementation doesn't even cache
 * anything it just forwards requests and responses.
 * This memobj is fully blocking (not non-blocking). Only a single request can
 * be outstanding at a time.
 */
class HybMem : public SimObject
{
  private:

    class CPUSidePort : public SlavePort
    {
      private:
        HybMem *owner;
        bool needRetry;
        PacketPtr blockedPacket;

      public:

        CPUSidePort(const std::string& name, HybMem *owner) :
            SlavePort(name, owner), owner(owner), needRetry(false),
            blockedPacket(nullptr)
        { }
        void sendPacket(PacketPtr pkt);
        AddrRangeList getAddrRanges() const override;
        void trySendRetry();

      protected:
        Tick recvAtomic(PacketPtr pkt) override//This is the function called whenever the CPU tries to make an atomic memory access.
        { panic("recvAtomic unimpl."); }
        void recvFunctional(PacketPtr pkt) override;
        bool recvTimingReq(PacketPtr pkt) override;
        void recvRespRetry() override;
    };

    class MemSidePort : public MasterPort
    {
      private:
        HybMem *owner;

        PacketPtr blockedPacket;

      public:
        MemSidePort(const std::string& name, HybMem *owner) :
            MasterPort(name, owner), owner(owner), blockedPacket(nullptr)
        { }
        void sendPacket(PacketPtr pkt);

      protected:
        bool recvTimingResp(PacketPtr pkt) override;
        void recvReqRetry() override;
        void recvRangeChange() override;
    };

    bool handleRequest(PacketPtr pkt);

    bool handleResponse(PacketPtr pkt);

    void handleFunctional(PacketPtr pkt);

    AddrRangeList getAddrRanges() const;

    void sendRangeChange();

    CPUSidePort instPort;    //the slave port,
    CPUSidePort dataPort;

    MemSidePort memPort;

    bool blocked;

  public:


    HybMem(HybMemParams *params);


    Port &getPort(const std::string &if_name,
                  PortID idx=InvalidPortID) override;
};


#endif // 
