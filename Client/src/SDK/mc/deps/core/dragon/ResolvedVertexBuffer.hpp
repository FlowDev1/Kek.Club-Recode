#pragma once

#include <cstdint>
#include <memory>
#include <variant>

#include "../bgfx/DynamicVertexBufferHandle.hpp"
#include "../bgfx/VertexBufferHandle.hpp"
#include "../bgfx/VertexDecl.hpp"
#include "../bgfx/VertexDeclHandle.hpp"
#include "VertexBufferView.hpp"

namespace dragon::mesh {
    class ResolvedVertexBuffer {
    public:
        std::variant<bgfx::VertexBufferHandle, bgfx::DynamicVertexBufferHandle> resource;
        uint32_t offset;
        uint32_t count;
        bgfx::VertexDeclHandle vertexDeclHandle;
        bgfx::VertexDecl vertexDecl;
        std::unique_ptr<VertexBufferView> storageView;
    };
}
