#pragma once

#include <cstddef>
#include <string_view>

class OffsetManager {
public:
    // SDK layout for Minecraft 1.26.65.01.
    static consteval std::ptrdiff_t getOffset(std::string_view name) {
        struct Entry {
            std::string_view name;
            std::ptrdiff_t offset;
        };
        constexpr Entry offsets[] = {
            {"Biome::id", 0x168},
            {"Biome::name", 0x190},
            {"FogUniformDescriptor::nameHash", 0x28},
            {"FogUniformWriter::table", 0x30},
            {"GameRenderer::glMatrix", 0x440},
            {"GameRenderer::lastViewMatrix", 0x3C0},
            {"GuiData::MousePos", 0x007A},
            {"GuiData::Resolution", 0x0050},
            {"GuiData::Scale", 0x005C},
            {"GuiData::mcResolution", 0x0040},
            {"GuiData::scalingMultiplier", 0x0060},
            {"GuiData::screenResRounded", 0x0048},
            {"GuiData::sliderAmount", 0x005C},
            {"LevelRenderer::atlasTexture", 0x1D0},
            {"LevelRenderer::blockTessellator", 0x3A0},
            {"LevelRenderer::cameraPos", 0x658},
            {"LevelRenderer::player", 0x480},
            {"LevelRenderer::renderChunkCoordinators", 0x28},
            {"MeshContext::currentShaderColor", 0x20},
            {"RendererContextD3D11::swapChain", 0x228},
            {"RendererContextD3D12::fatalError", 0x19F88},
            {"ResourcePointer::controlBlock", 0x8},
            {"ScreenContext::meshContext", 0x10},
            {"ScreenContext::tessellator", 0xB0},
            {"TextureGroup::baseSubobject", 0x18},
            {"TextureGroup::lruCache", 0x240},
            {"TextureGroup::textures", 0x1A8},
            {"TextureGroup::uiTextureInfo", 0x230},
        };
        for (const auto& entry : offsets) {
            if (entry.name == name)
                return entry.offset;
        }
        throw "Unknown SDK offset";
    }
};

#define GET_OFFSET(name) OffsetManager::getOffset(name)
