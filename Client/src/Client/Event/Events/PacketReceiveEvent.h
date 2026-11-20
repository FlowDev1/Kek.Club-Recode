#pragma once

#include "../CancellableEvent.h"
#include "../../../SDK/mc/common/network/Packet.h"

class PacketReceiveEvent : public CancellableEvent {
public:
    explicit PacketReceiveEvent(Packet* packet) : packet(packet) {}

    Packet* packet = nullptr;

    template <std::derived_from<Packet> T>
    T* as() {
        return reinterpret_cast<T*>(packet);
    }
};