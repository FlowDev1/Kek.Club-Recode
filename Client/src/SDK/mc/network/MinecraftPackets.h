#pragma once

#include "../common/network/Packet.h"
#include "../enums/MinecraftPacketIds.h"

class MinecraftPackets {
public:
    static std::shared_ptr<Packet> createPacket(MinecraftPacketIds id);
};