#include "Packet.h"

#include "../../../../Utils/Memory.h"

MinecraftPacketIds Packet::getId() const {
    return Memory::callVFunc<1, MinecraftPacketIds()>(this);
}

std::string Packet::getName() const {
    return Memory::callVFunc<2, std::string()>(this);
}