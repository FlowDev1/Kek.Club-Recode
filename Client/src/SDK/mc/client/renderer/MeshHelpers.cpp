#include "MeshHelpers.h"

#include "../../../../Signatures/SigManager.h"

/* Having a constant ClientTexture reference parameter and a variant parameter in this function doesn't make sense.
Additionally, trying to use a texture in the above function resulting in a crash doesn't make sense either.
However, for now, I'll keep it as is. */

void MeshHelpers::renderMesh(ScreenContext& screenContext, Tessellator& tessellator, const mce::MaterialPtr& material, const std::variant<std::monostate, mce::ClientTexture, mce::ServerTexture, mce::TexturePtr>& texture) {
    static auto renderMesh = Memory::getFunction<&MeshHelpers::renderMesh>(GET_SIGNATURE("MeshHelpers::renderMeshImmediately1"));
    renderMesh(screenContext, tessellator, material, texture);
}

void MeshHelpers::renderMeshC(ScreenContext& screenContext, Tessellator& tessellator, const mce::MaterialPtr& material, const mce::ClientTexture& texture, const std::variant<std::monostate, mce::ClientTexture, mce::ServerTexture, mce::TexturePtr>& textureType) {
    static auto renderMesh = Memory::getFunction<&MeshHelpers::renderMeshC>(GET_SIGNATURE("MeshHelpers::renderMeshImmediately2"));
    renderMesh(screenContext, tessellator, material, texture, textureType);
}