#pragma once

#include "GameSession.hpp"

#include "../wrapper/StackRefResult.hpp"
#include "gamerefs_entity/EntityRegistry.hpp"

class Minecraft {
public:
    std::unique_ptr<GameSession>& getGameSession();

    StackRefResult<EntityRegistry> getEntityRegistry();
};