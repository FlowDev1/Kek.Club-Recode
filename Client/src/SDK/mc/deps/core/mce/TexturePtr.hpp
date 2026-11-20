#pragma once

#include "../../../client/renderer/BedrockTextureData.hpp"
#include "../../../client/resource/ResourceLocation.hpp"

namespace mce {
    class TexturePtr {
    public:
        std::shared_ptr<BedrockTextureData const> clientTexture;
        std::shared_ptr<ResourceLocation> resourceLocation;
    };
}