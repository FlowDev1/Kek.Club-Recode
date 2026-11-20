#pragma once

#include "../../common/world/ECS/IEntityComponent.hpp"

struct RuntimeIDComponent : IEntityComponent {
    ActorRuntimeID runtimeID;
};