#pragma once

namespace bgfx::RendererType {
    enum Enum {
        BGFX_NOOP,
        BGFX_D3D11,
        BGFX_D3D12,
        BGFX_D3D12RTX,
        BGFX_GNM,
        BGFX_UNK1,
        BGFX_UNK2,
        BGFX_OPENGLES,
        BGFX_OPENGL,
        BGFX_VULKAN,
        BGFX_VULKAN_1_3,
        BGFX_NVN
    };
}
