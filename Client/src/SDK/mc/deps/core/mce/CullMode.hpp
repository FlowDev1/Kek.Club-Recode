#pragma once

#include <cstdint>

namespace mce {
    enum CullMode : uint8_t {
        CullNone,
        CullFront,
        CullBack
    };
}
