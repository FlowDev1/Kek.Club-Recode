#pragma once

#include "../ECS/EntityId.h"

class EntityRegistry : std::enable_shared_from_this<EntityRegistry> {
public:
    std::string debugName; // 0x10
    entt::basic_registry<EntityId> registry; // 0x30
    uint32_t id; // 0x150
};
