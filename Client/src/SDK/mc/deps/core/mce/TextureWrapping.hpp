#pragma once

#include <cstdint>

namespace mce {
    enum TextureWrapping : uint8_t {
        ClampToEdge,
        Repeat,
        MirroredRepeat
    };
}
