#include "Packet.hpp"

#include "../../../../Utils/Memory.hpp"

MinecraftPacketIds Packet::getId() const {
    return Memory::callVFunc<1, MinecraftPacketIds()>(this);
}

std::string Packet::getName() const {
    return Memory::callVFunc<2, std::string()>(this);
}