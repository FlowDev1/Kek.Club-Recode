#pragma once

#include "MouseActionType.hpp"

class MouseAction {
public: // These fields have not been verified, but they are likely correct and most work as expected
    int16_t x;
    int16_t y;
    int16_t dx;
    int16_t dy;
    MouseActionType action;
    int8_t data; // Scroll up = 120, scroll down = -120 (127 and -128 may appear)
    int32_t pointerId;
    bool forceMotionlessPointer;
};