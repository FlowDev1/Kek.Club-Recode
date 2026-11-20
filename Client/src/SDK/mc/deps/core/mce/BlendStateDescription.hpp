#pragma once

#include <cstdint>

#include "BlendTarget.hpp"

namespace mce {
    struct BlendStateDescription {
        BlendTarget blendSource;
        BlendTarget blendDestination;
        BlendTarget alphaSource;
        BlendTarget alphaDestination;
        uint8_t colorWriteMask;
        bool enableBlend;
        bool enableAlphaToCoverage;
    };
}
