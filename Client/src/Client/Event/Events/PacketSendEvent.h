#pragma once

#include "../CancellableEvent.h"
#include "../../SDK/mc/common/network/Packet.h"

class PacketSendEvent : public CancellableEvent {
public:
    explicit PacketSendEvent(Packet& packet) : packet(packet) {}

    Packet& packet;

    template <std::derived_from<Packet> T>
    T& as() {
        return reinterpret_cast<T&>(packet);
    }
};