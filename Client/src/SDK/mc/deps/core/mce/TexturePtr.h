#pragma once

#include "../../../client/renderer/BedrockTextureData.h"
#include "../../../client/resource/ResourceLocation.h"

namespace mce {
    class TexturePtr {
    public:
        std::shared_ptr<BedrockTextureData const> clientTexture;
        std::shared_ptr<ResourceLocation> resourceLocation;
    };
}