#include "LoopbackPacketSender.hpp"

#include "../../../../Utils/Memory.hpp"

void LoopbackPacketSender::sendToServer(Packet& packet) {
    Memory::callVFunc<2, &LoopbackPacketSender::sendToServer>(this, packet);
}