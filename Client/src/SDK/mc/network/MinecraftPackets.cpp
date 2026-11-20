#include "MinecraftPackets.hpp"

#include "../../../Signatures/SigManager.hpp"

std::shared_ptr<Packet> MinecraftPackets::createPacket(MinecraftPacketIds id) {
    static auto function = Memory::getFunction<&MinecraftPackets::createPacket>(Memory::addressFromSigOffset(GET_SIGNATURE("MinecraftPackets::createPacket"), 1));
    return function(id);
}