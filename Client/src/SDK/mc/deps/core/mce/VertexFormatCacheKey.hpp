#pragma once

#include <cstdint>

#include "VertexFormat.hpp"

namespace mce {
    struct VertexFormatCacheKey {
        VertexFormat vertexFormat;
        uint32_t attributeListIndex;
    };
}
