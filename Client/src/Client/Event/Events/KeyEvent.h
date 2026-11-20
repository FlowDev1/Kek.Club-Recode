#pragma once

#include "../CancellableEvent.h"

class KeyEvent : public CancellableEvent {
public:
    KeyEvent(const unsigned char key, const bool pressed) : key(key), pressed(pressed) {}

    [[nodiscard]] unsigned char getKey() const { return key; }
    [[nodiscard]] bool isPressed() const { return pressed; }

private:
    unsigned char key;
    bool pressed;
};