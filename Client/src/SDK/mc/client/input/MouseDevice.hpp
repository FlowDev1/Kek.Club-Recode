#pragma once

#include "MouseAction.hpp"

class MouseDevice {
public: // Size 0x38 (all the below information was verified as of 1.20.80)
    int32_t _index; // 0x0
    int16_t _x; // 0x4
    int16_t _y; // 0x6
    int16_t _dx; // 0x8
    int16_t _dy; // 0xA
    int16_t _xOld; // 0xC
    int16_t _yOld; // 0xE
    int8_t _buttonStates[5]; // 0x10
    std::vector<MouseAction> _inputs; // 0x18
    int32_t _firstMovementType; // 0x30
};