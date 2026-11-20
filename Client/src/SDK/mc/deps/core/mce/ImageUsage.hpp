#pragma once

#include <cstdint>

namespace mce {
    enum class ImageUsage : uint8_t {
        UnknownUsage = 0x0,
        sRGB = 0x1,
        Data = 0x2,
    };
}
