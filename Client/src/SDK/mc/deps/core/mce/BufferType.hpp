#pragma once

#include <cstdint>

namespace mce {
    enum BufferType : uint8_t {
        VertexBuffer,
        IndexBuffer,
        MaxBufferTypes,
        UnknownBufferType
    };
}
