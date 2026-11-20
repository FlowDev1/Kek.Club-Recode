#pragma once

#include "../../../deps/core/ShaderColor.h"
#include "../../../deps/core/mce/Clock.h"
#include "../Tessellator.h"

class ScreenContext { // I will add proper inheritance later
public:
    mce::Clock& getClock();
    Tessellator& getTessellator();
    ShaderColor& getCurrentShaderColor();
};