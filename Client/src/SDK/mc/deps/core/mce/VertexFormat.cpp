#include "VertexFormat.hpp"

namespace mce {
    VertexFormat::VertexFormat() {
        memset(_fieldOffset, -1, VertexFormatFieldOffsetCount * sizeof(uint16_t));
    }
}
