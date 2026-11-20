#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace mce {
    constexpr size_t VertexFormatFieldOffsetCount = 15;

    struct VertexFormat {
        uint16_t fieldMask{};
        uint16_t _fieldOffset[VertexFormatFieldOffsetCount];
        uint16_t vertexSize{};
        bool allowHalfFloats = true;

        VertexFormat();
    };
}
