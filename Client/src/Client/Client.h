#pragma once

#include "Event/Events/ClientTickEvent.h"
#include "Event/Events/GameTickEvent.h"
#include "Event/Events/KeyEvent.h"

class Client {
public:
    [[nodiscard]] bool isKeyDown(unsigned char key) const;

    std::array<bool, 256> keys;

    void subscribeEvents();
    void unsubscribeEvents();
    void onKeyUpdate(KeyEvent&) const;
    void onGameTick(const GameTickEvent&);
    void onClientTick(const ClientTickEvent&);
};

extern Client g_Client; // Will be renamed once there is a name for the client