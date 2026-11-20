#pragma once

#include "../../common/network/Packet.hpp"
#include "../../common/world/ActorRuntimeID.hpp"
#include "../../../../Utils/Math/Vectors.hpp"
#include "../../common/world/level/Tick.hpp"

class SetActorMotionPacket : public Packet {
public:
    ActorRuntimeID runtimeId; // 0x30
    Vec3 motion; // 0x38
    Tick tick; // 0x48

    SetActorMotionPacket() : Packet() {}
    SetActorMotionPacket(ActorRuntimeID runtimeId, Vec3 motion, Tick tick = 0);
};