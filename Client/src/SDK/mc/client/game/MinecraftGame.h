#pragma once

#include "IMinecraftGame.h"
#include "IClientInstance.h"

#include "../gui/gui/FontRepository.h"

class MinecraftGame : public IMinecraftGame {
public:
    std::map<uint8_t, std::shared_ptr<IClientInstance>>& getClientInstances();

    FontRepository* getFontRepository();
};