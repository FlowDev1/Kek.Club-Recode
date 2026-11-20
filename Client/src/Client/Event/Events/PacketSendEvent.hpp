#pragma once

#include "../CancellableEvent.hpp"
#include "../../../SDK/mc/common/network/Packet.hpp"

class PacketSendEvent : public CancellableEvent {
public:
    explicit PacketSendEvent(Packet& packet) : packet(packet) {}

    Packet& packet;

    template <std::derived_from<Packet> T>
    T& as() {
        return reinterpret_cast<T&>(packet);
    }
};