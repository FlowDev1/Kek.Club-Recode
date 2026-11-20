#pragma once

#include "../network/NetEventCallback.h"

class GameSession {
public:
    std::unique_ptr<NetEventCallback>& getClientNetworkHandler();
};