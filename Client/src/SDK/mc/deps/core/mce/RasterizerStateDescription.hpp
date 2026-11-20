#pragma once

#include "CullMode.hpp"
#include "FillMode.hpp"

namespace mce {
    struct RasterizerStateDescription {
        float depthBias;
        float slopeScaledDepthBias;
        CullMode cullMode;
        FillMode fillMode;
    };
}
