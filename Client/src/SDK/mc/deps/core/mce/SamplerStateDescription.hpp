#pragma once

#include <cstdint>

#include "ComparisonFunc.hpp"
#include "TextureFiltering.hpp"
#include "TextureWrappingDescription.hpp"

namespace mce {
    struct SamplerStateDescription {
        TextureFiltering textureFilter;
        TextureWrappingDescription textureWrappingDescription;
        uint32_t shaderStagesBits;
        int16_t samplerIndex;
        ComparisonFunc comparisonFunc;
    };
}
