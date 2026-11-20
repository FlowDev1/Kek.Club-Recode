#pragma once

#include "Packet.h"
#include "PacketSender.h"

class LoopbackPacketSender : public PacketSender {
public:
    void sendToServer(Packet& packet);
};