#pragma once

#include "../network/NetEventCallback.hpp"

class GameSession {
public:
    std::unique_ptr<NetEventCallback>& getClientNetworkHandler();
};