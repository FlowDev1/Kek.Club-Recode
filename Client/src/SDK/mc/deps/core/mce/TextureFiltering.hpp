#pragma once

#include <cstdint>

namespace mce {
    enum TextureFiltering : uint8_t {
        PointFiltering,
        BilinearFiltering,
        TrilinearFiltering,
        MipMapBilinearFiltering,
        TexelAA,
        PCF
    };
}
