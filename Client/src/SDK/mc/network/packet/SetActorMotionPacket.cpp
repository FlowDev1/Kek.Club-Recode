#include "SetActorMotionPacket.h"

#include "../MinecraftPackets.h"

SetActorMotionPacket::SetActorMotionPacket(const ActorRuntimeID runtimeId, const Vec3 motion, const Tick tick) : Packet() {
    vTable = MinecraftPackets::createPacket(MinecraftPacketIds::SetActorMotion)->vTable;
    this->runtimeId = runtimeId;
    this->motion = motion;
    this->tick = tick;
}