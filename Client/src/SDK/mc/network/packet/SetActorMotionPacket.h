#pragma once

#include "../../common/network/Packet.h"
#include "../../common/world/ActorRuntimeID.h"
#include "../../../../Utils/Math/Vectors.h"
#include "../../common/world/level/Tick.h"

class SetActorMotionPacket : public Packet {
public:
    ActorRuntimeID runtimeId; // 0x30
    Vec3 motion; // 0x38
    Tick tick; // 0x48

    SetActorMotionPacket() : Packet() {}
    SetActorMotionPacket(ActorRuntimeID runtimeId, Vec3 motion, Tick tick = 0);
};