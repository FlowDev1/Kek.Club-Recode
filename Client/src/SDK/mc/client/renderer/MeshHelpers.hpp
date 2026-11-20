#pragma once

#include "MaterialPtr.hpp"
#include "Tessellator.hpp"
#include "screen/ScreenContext.hpp"
#include "../../deps/core/mce/TexturePtr.hpp"
#include "../../deps/core/mce/ClientTexture.hpp"
#include "../../deps/core/mce/ServerTexture.hpp"

class MeshHelpers {
public:
    static void renderMesh(ScreenContext& screenContext, Tessellator& tessellator, const mce::MaterialPtr& material, const std::variant<std::monostate, mce::ClientTexture, mce::ServerTexture, mce::TexturePtr>& texture = {});
    static void renderMeshC(ScreenContext& screenContext, Tessellator& tessellator, const mce::MaterialPtr& material, const mce::ClientTexture& texture, const std::variant<std::monostate, mce::ClientTexture, mce::ServerTexture, mce::TexturePtr>& textureType = {});
};