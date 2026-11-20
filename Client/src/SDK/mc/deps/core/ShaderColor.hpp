#pragma once

#include "mce/Color.hpp"

class ShaderColor {
public:
    mce::Color color;
    bool dirty{};
};