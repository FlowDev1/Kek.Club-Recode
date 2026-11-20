#pragma once

#include "MaterialPtr.h"
#include "Tessellator.h"
#include "screen/ScreenContext.h"
#include "../../deps/core/mce/TexturePtr.h"
#include "../../deps/core/mce/ClientTexture.h"
#include "../../deps/core/mce/ServerTexture.h"

class MeshHelpers {
public:
    static void renderMesh(ScreenContext& screenContext, Tessellator& tessellator, const mce::MaterialPtr& material, const std::variant<std::monostate, mce::ClientTexture, mce::ServerTexture, mce::TexturePtr>& texture = {});
    static void renderMeshC(ScreenContext& screenContext, Tessellator& tessellator, const mce::MaterialPtr& material, const mce::ClientTexture& texture, const std::variant<std::monostate, mce::ClientTexture, mce::ServerTexture, mce::TexturePtr>& textureType = {});
};