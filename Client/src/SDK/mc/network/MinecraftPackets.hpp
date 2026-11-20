#pragma once

#include "../common/network/Packet.hpp"
#include "../enums/MinecraftPacketIds.hpp"

class MinecraftPackets {
public:
    static std::shared_ptr<Packet> createPacket(MinecraftPacketIds id);
};