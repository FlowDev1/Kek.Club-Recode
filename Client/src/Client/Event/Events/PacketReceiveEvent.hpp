#pragma once

#include "../CancellableEvent.hpp"
#include "../../../SDK/mc/common/network/Packet.hpp"

class PacketReceiveEvent : public CancellableEvent {
public:
    explicit PacketReceiveEvent(Packet* packet) : packet(packet) {}

    Packet* packet = nullptr;

    template <std::derived_from<Packet> T>
    T* as() {
        return reinterpret_cast<T*>(packet);
    }
};