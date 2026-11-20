#pragma once

#include <cstdint>

namespace dragon {
    enum TextureUsageFlag : uint8_t {
        ReadSrc,
        CopyDst,
        RenderDst,
        ComputeDst,
        Count
    };
}
