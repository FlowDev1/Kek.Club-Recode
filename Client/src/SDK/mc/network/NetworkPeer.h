#pragma once

class NetworkPeer {
public:
    using PacketRecvTimepoint = std::chrono::steady_clock::time_point;

    enum class Reliability : int32_t {
        Reliable = 0,
        ReliableOrdered = 1,
        Unreliable = 2,
        UnreliableSequenced = 3
    };
};