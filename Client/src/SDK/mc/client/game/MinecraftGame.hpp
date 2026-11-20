#pragma once

#include "IMinecraftGame.hpp"
#include "IClientInstance.hpp"

#include "../gui/gui/FontRepository.hpp"

class MinecraftGame : public IMinecraftGame {
public:
    std::map<uint8_t, std::shared_ptr<IClientInstance>>& getClientInstances();

    FontRepository* getFontRepository();
};