#pragma once

#include "Packet.hpp"
#include "PacketSender.hpp"

class LoopbackPacketSender : public PacketSender {
public:
    void sendToServer(Packet& packet);
};