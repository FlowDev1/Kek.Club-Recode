#include "LoopbackPacketSender.h"

#include "../../../../Utils/Memory.h"

void LoopbackPacketSender::sendToServer(Packet& packet) {
    Memory::callVFunc<2, &LoopbackPacketSender::sendToServer>(this, packet);
}