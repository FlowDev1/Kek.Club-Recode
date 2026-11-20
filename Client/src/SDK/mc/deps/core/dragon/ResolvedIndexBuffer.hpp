#pragma once

#include <cstdint>
#include <memory>
#include <variant>

#include "../bgfx/DynamicIndexBufferHandle.hpp"
#include "../bgfx/IndexBufferHandle.hpp"
#include "IndexBufferView.hpp"
#include "IndexSize.hpp"

namespace dragon::mesh {
    class ResolvedIndexBuffer {
        std::variant<bgfx::IndexBufferHandle, bgfx::DynamicIndexBufferHandle> resource;
        uint32_t offset;
        uint32_t count;
        IndexSize indexSize;
        std::unique_ptr<IndexBufferView> storageView;
    };
}
