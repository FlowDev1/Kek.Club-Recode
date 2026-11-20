#pragma once

#include "ComparisonFunc.hpp"
#include "StencilOp.hpp"

namespace mce {
    struct StencilFaceDescription {
        ComparisonFunc stencilFunc;
        StencilOp stencilDepthFailOp;
        StencilOp stencilPassOp;
        StencilOp stencilFailOp;
    };
}
