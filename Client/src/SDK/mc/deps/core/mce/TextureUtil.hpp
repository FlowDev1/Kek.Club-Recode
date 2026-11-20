#pragma once

#include "TextureFormat.hpp"

namespace mce {
    class TextureUtil {
    public:
        static int getBytesPerPixel(const TextureFormat format);
    };
}
