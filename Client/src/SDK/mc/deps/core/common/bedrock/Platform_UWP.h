#pragma once

#include "../../../../client/game/MinecraftGame.h"

#include "../../../application/AppPlatform.h"

namespace Bedrock {
    class Platform_UWP {
    public:
        MinecraftGame* getMinecraftGame();

        AppPlatform* getAppPlatform();
    };
}