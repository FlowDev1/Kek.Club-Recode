#pragma once

#include "../../../../client/game/MinecraftGame.hpp"

#include "../../../application/AppPlatform.hpp"

namespace Bedrock {
    class Platform_UWP {
    public:
        MinecraftGame* getMinecraftGame();

        AppPlatform* getAppPlatform();
    };
}