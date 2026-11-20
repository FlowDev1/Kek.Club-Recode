#pragma once

#include <cstdint>

namespace cg {
    enum class ImageType : uint8_t {
        Texture2D,
        CubemapDeprecated,
        Texture3D,
        TextureCube
    };
}
