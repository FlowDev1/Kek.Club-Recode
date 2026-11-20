#pragma once

#include "Event/Events/ClientTickEvent.hpp"
#include "Event/Events/GameTickEvent.hpp"
#include "Event/Events/KeyEvent.hpp"

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