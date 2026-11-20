#pragma once

#include "../../../deps/core/ShaderColor.hpp"
#include "../../../deps/core/mce/Clock.hpp"
#include "../Tessellator.hpp"

class ScreenContext { // I will add proper inheritance later
public:
    mce::Clock& getClock();
    Tessellator& getTessellator();
    ShaderColor& getCurrentShaderColor();
};