#pragma once

#include "../../common/world/ECS/IEntityComponent.h"

struct RuntimeIDComponent : IEntityComponent {
    ActorRuntimeID runtimeID;
};