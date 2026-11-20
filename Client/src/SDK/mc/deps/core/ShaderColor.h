#pragma once

#include "mce/Color.h"

class ShaderColor {
public:
    mce::Color color;
    bool dirty{};
};