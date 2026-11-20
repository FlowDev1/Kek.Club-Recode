#pragma once

#include "GameSession.h"

#include "../wrapper/StackRefResult.h"
#include "gamerefs_entity/EntityRegistry.h"

class Minecraft {
public:
    std::unique_ptr<GameSession>& getGameSession();

    StackRefResult<EntityRegistry> getEntityRegistry();
};