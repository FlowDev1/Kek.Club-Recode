#pragma once

#include "../CancellableEvent.hpp"

class MouseEvent : public CancellableEvent {
public:
    MouseEvent(const char actionButtonId, const int8_t buttonData, const int16_t x, const int16_t y) : actionButtonId(actionButtonId), buttonData(buttonData), x(x), y(y) {}

    char actionButtonId;
    int8_t buttonData;
    int16_t x;
    int16_t y;
};