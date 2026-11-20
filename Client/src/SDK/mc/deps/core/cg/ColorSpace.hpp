#pragma once

#include <cstdint>

namespace cg {
    enum class ColorSpace : int8_t {
        Unknown = 0x0,
        sRGB = 0x1,
        Linear = 0x2
    };
}
