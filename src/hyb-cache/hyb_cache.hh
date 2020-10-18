#ifndef _HYB_CACHE_HH__
#define _HYB_CACHE_HH_
#include <unordered_map>
#include "params/HybCache.hh"
#include "sim/clocked_object.hh"
#include "base/statistics.hh"
#include "mem/port.hh"

class HybCache : public ClockedObject
{
    private:

    class CPUSidePort : public SlavePort
    {
      private:
        int id;
        HybCache *owner;
        bool needRetry;
        PacketPtr blockedPacket;

      public:
        CPUSidePort(const std::string& name, int id, HybCache *owner) :
            SlavePort(name, owner), id(id), owner(owner), needRetry(false),
            blockedPacket(nullptr)
        { }
        void sendPacket(PacketPtr pkt);
        AddrRangeList getAddrRanges() const override;
        void trySendRetry();

      protected:
        Tick recvAtomic(PacketPtr pkt) override
        { panic("recvAtomic unimpl."); }
        void recvFunctional(PacketPtr pkt) override;
        bool recvTimingReq(PacketPtr pkt) override;
        void recvRespRetry() override;
    };

    class MemSidePort : public MasterPort
    {
      private:
        HybCache *owner;
        PacketPtr blockedPacket;

      public:
        MemSidePort(const std::string& name, HybCache *owner) :
            MasterPort(name, owner), owner(owner), blockedPacket(nullptr)
        { }
        void sendPacket(PacketPtr pkt);

      protected:
        bool recvTimingResp(PacketPtr pkt) override;
        void recvReqRetry() override;
        void recvRangeChange() override;
    };


    bool handleRequest(PacketPtr pkt, int port_id);
    bool handleResponse(PacketPtr pkt);
    void sendResponse(PacketPtr pkt);
    void handleFunctional(PacketPtr pkt);
    void accessTiming(PacketPtr pkt);
    bool accessFunctional(PacketPtr pkt);
    void insert(PacketPtr pkt);
    AddrRangeList getAddrRanges() const;
    void sendRangeChange() const;

    const Cycles latency;
    const unsigned blockSize;
    const unsigned capacity;
    std::vector<CPUSidePort> cpuPorts;
    MemSidePort memPort;
    bool blocked;

    PacketPtr originalPacket;

    int waitingPortId;

    Tick missTime;

    std::unordered_map<Addr, uint8_t*> cacheStore;

    Stats::Scalar hits;
    Stats::Scalar misses;
    Stats::Histogram missLatency;
    Stats::Formula hitRatio;

  public:
    HybCache(HybCacheParams *params);

    Port &getPort(const std::string &if_name, PortID idx=InvalidPortID) override;

    void regStats() override;
};

#endif // _HYB_CACHE_HH__