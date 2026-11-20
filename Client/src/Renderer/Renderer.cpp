#include "Renderer.h"

#include "../SDK/SDK.h"
#include "../SDK/mc/client/renderer/MeshHelpers.h"
#include "../Utils/Files.h"
#include "../Utils/Math/Math.h"
#include "../Utils/Rendering/MaterialStorage.h"

void Renderer::update(ScreenView* screenView, UIRenderContext* uiRenderContext) {
    SDK::screenView = screenView;
    SDK::uiRenderContext = reinterpret_cast<MinecraftUIRenderContext*>(uiRenderContext);
    SDK::screenContext = SDK::uiRenderContext->getScreenContext();
    SDK::tessellator = &SDK::uiRenderContext->getScreenContext()->getTessellator();
}

void Renderer::setColor(const mce::Color& color) {
    const auto screenContext = SDK::screenContext;

    if (screenContext == nullptr)
        return;

    screenContext->getCurrentShaderColor().color = color;
}

mce::MaterialPtr* Renderer::getUIFillColorMaterial() {
    return materialStorage.getMaterial(MaterialStorage::Material::ui_fill_color);
}

mce::MaterialPtr* Renderer::getUITexturedMaterial() {
    return materialStorage.getMaterial(MaterialStorage::Material::ui_textured);
}

mce::TexturePtr Renderer::getTexture(const std::string& textureName, const bool external) {
    ResourceLocation resourceLoc(Files::getAssetsFolder() + textureName, external);
    return SDK::uiRenderContext->getTexture(resourceLoc, false);
}

void Renderer::drawText(const Fonts font, const Vec2& pos, const std::string& text, const mce::Color& color, const float size, const float alpha, const bool shadow) {
    if (SDK::minecraftGame == nullptr || SDK::uiRenderContext == nullptr)
        return;

    Font* fontPtr = SDK::minecraftGame->getFontRepository()->getFont(font);
    const TextMeasureData textMeasureData(size, 0, shadow);
    SDK::uiRenderContext->drawText(*fontPtr, RectangleArea(pos.x, 0, pos.y, 0), text, color, alpha, ui::TextAlignment::Left, textMeasureData);
}

void Renderer::flushText() {
    if (SDK::uiRenderContext == nullptr)
        return;

    SDK::uiRenderContext->flushText(0);
}

void Renderer::begin(const mce::PrimitiveMode mode) {
    if (SDK::tessellator == nullptr)
        return;

    SDK::tessellator->begin(mode);
}

void Renderer::render(const mce::MaterialPtr* material) {
    if (SDK::screenContext == nullptr)
        ClientAssert(SDK::screenContext, "ScreenContext was null when trying to render!");

    MeshHelpers::renderMesh(*SDK::screenContext, *SDK::tessellator, *material);
}

void Renderer::render(const std::string& path, const mce::MaterialPtr* material, const bool external) {
    ResourceLocation location;

    if (external)
        location = ResourceLocation(Files::getRoamingState() + "Assets\\" + path, true);
    else
        location = ResourceLocation(path, false);

    const mce::TexturePtr texture = SDK::uiRenderContext->getTexture(location, false);

    render(texture.clientTexture->clientTexture, material);
}

void Renderer::render(const mce::ClientTexture& texture, const mce::MaterialPtr* material) {
    if (SDK::screenContext == nullptr)
        ClientAssert(SDK::screenContext, "ScreenContext was null when trying to render!");

    MeshHelpers::renderMeshC(*SDK::screenContext, *SDK::tessellator, *material, texture);
}

void Renderer::drawImage(const std::string& path, const Vec2& pos, const Vec2& size, const mce::Color& color, const bool external) {
    static Vec2 uvPos{0.f, 0.f};
    drawImage(path, pos, size, uvPos, {1.f, 1.f}, color, external);
}

void Renderer::drawImage(const std::string& path, const Vec2& pos, const Vec2& size, Vec2& uvPos, const Vec2& uvSize, const mce::Color& color, const bool external) {
    ResourceLocation location;

    if (external)
        location = ResourceLocation(Files::getRoamingState() + "Assets\\" + path, true);
    else
        location = ResourceLocation(path, false);

    const mce::TexturePtr texture = SDK::uiRenderContext->getTexture(location, false);

    begin();
    addImage(pos, size, uvPos, uvSize, color);
    render(texture.clientTexture->clientTexture);
}

void Renderer::drawImageEx(const std::string& path, const QuadVertexHolder& pos, const QuadColorHolder& colors, const bool external) {
    ResourceLocation location;

    if (external)
        location = ResourceLocation(Files::getRoamingState() + "Assets\\" + path, true);
    else
        location = ResourceLocation(path, false);

    const mce::TexturePtr texture = SDK::uiRenderContext->getTexture(location, false);

    begin();
    addImageEx(pos, colors);
    render(texture.clientTexture->clientTexture);
}

void Renderer::drawTriangle(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const mce::Color& color) {
    begin();
    addTriangle(pos1, pos2, pos3, color);
    render();
}

void Renderer::drawRect(const Vec2& pos, const Vec2& size, const float lineSize, const mce::Color& color) {
    begin();
    addRect(pos, size, lineSize, color);
    render();
}

void Renderer::fillRect(const Vec2& pos, const Vec2& size, const mce::Color& color) {
    begin();
    addFilledRect(pos, size, color);
    render();
}

void Renderer::drawRoundedRect(const Vec2& pos, const Vec2& size, const float stepSize, const mce::Color& color, const uint16_t flags, const float radius) {
    begin();
    addRoundedRect(pos, size, stepSize, color, flags, radius);
    render();
}

void Renderer::addImage(const Vec2& pos, const Vec2& size, const mce::Color& color) {
    static Vec2 uvPos{0.f, 0.f};

    addImage(pos, size, uvPos, {1.f, 1.f}, color);
}

void Renderer::addImage(const Vec2& pos, const Vec2& size, Vec2& uvPos, const Vec2& uvSize, const mce::Color& color) {
    const auto tessellator = SDK::tessellator;

    if (tessellator == nullptr)
        return;

    tessellator->colorC(color);
    tessellator->simpleQuad(pos, size, uvPos, uvSize);
}

void Renderer::addImageEx(const QuadVertexHolder& pos, const QuadColorHolder& colors) {
    const auto tessellator = SDK::tessellator;

    if (tessellator == nullptr)
        return;

    tessellator->colorC(colors.col1);
    tessellator->vertexUVV(pos.pos1, pos.uv1);

    tessellator->colorC(colors.col3);
    tessellator->vertexUVV(pos.pos3, pos.uv3);

    tessellator->colorC(colors.col2);
    tessellator->vertexUVV(pos.pos2, pos.uv2);


    tessellator->colorC(colors.col3);
    tessellator->vertexUVV(pos.pos3, pos.uv3);

    tessellator->colorC(colors.col4);
    tessellator->vertexUVV(pos.pos4, pos.uv4);

    tessellator->colorC(colors.col2);
    tessellator->vertexUVV(pos.pos2, pos.uv2);
}

void Renderer::addTriangle(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const mce::Color& color) {
    const auto tessellator = SDK::tessellator;

    if (tessellator == nullptr)
        return;

    tessellator->colorC(color);

    tessellator->vertex(pos1.x, pos1.y, 0.f);
    tessellator->vertex(pos2.x, pos2.y, 0.f);
    tessellator->vertex(pos3.x, pos3.y, 0.f);
}

void Renderer::addRect(const Vec2& pos, const Vec2& size, const float lineSize, const mce::Color& color) {
    if (SDK::tessellator == nullptr || color.a == 0.f)
        return;

    if (color.a == 1.f) {
        addFilledRect(pos, {size.x, lineSize}, color);
        addFilledRect(pos, {lineSize, size.y}, color);
        addFilledRect({pos.x + size.x - lineSize, pos.y}, {lineSize, size.y}, color);
        addFilledRect({pos.x, pos.y + size.y - lineSize}, {size.x, lineSize}, color);
    } else {
        float lsx = lineSize, lsy = lineSize;

        if ((size.x - pos.x) / 2.f < lsx)
            lsx = (size.x - pos.x) / 2.f;

        if ((size.y - pos.y) / 2.f < lsy)
            lsy = (size.y - pos.y) / 2.f;

        addFilledRect(pos, {size.x, lsy}, color);
        addFilledRect({pos.x, pos.y + lsy}, {lsx, size.y - lsy}, color);
        addFilledRect({pos.x + size.x - lsx, pos.y + lsy}, {lsx, size.y - lsy}, color);
        addFilledRect({pos.x + lsx, pos.y + size.y - lsy}, {size.x - lsx * 2.f, lsy}, color);
    }
}

void Renderer::addFilledRect(const Vec2& pos, const Vec2& size, const mce::Color& color) {
    if (SDK::tessellator == nullptr || color.a == 0.f)
        return;

    addTriangle({pos.x, pos.y}, {pos.x, pos.y + size.y}, {pos.x + size.x, pos.y}, color);
    addTriangle({pos.x, pos.y + size.y}, {pos.x + size.x, pos.y + size.y}, {pos.x + size.x, pos.y}, color);
}

void Renderer::addRoundedRect(const Vec2& pos, const Vec2& size, const float stepSize, const mce::Color& color, const uint16_t flags, const float radius) {
    const auto tessellator = SDK::tessellator;

    if (tessellator == nullptr || color.a == 0)
        return;

    constexpr uint16_t FLAG_CTL = 8; // Top left corner
    constexpr uint16_t FLAG_CTR = 4; // Top right corner
    constexpr uint16_t FLAG_CBL = 2; // Bottom left corner
    constexpr uint16_t FLAG_CBR = 1; // Bottom right corner
    constexpr uint16_t FLAG_DRM = 16; // Filler rectangle middle
    constexpr uint16_t FLAG_DRT = 32; // Filler rectangle top
    constexpr uint16_t FLAG_DRB = 64; // Filler rectangle bottom
    constexpr uint16_t FLAG_DRL = 128; // Filler rectangle left
    constexpr uint16_t FLAG_DRR = 256; // Filler rectangle right

    const float offset = radius;

    auto addRectIf = [&](const bool condition, const Vec2& posOffset, const Vec2& sizeOffset) {
        if (!condition)
            addFilledRect({pos.x + posOffset.x, pos.y + posOffset.y}, sizeOffset, color);
    };

    addRectIf(flags & FLAG_DRM, {offset, offset}, {size.x - offset * 2.f, size.y - offset * 2.f});
    addRectIf(flags & FLAG_DRT, {offset, 0}, {size.x - offset * 2.f, offset});
    addRectIf(flags & FLAG_DRB, {offset, size.y - offset}, {size.x - offset * 2.f, offset});
    addRectIf(flags & FLAG_DRL, {0, offset}, {offset, size.y - offset * 2.f});
    addRectIf(flags & FLAG_DRR, {size.x - offset, offset}, {offset, size.y - offset * 2.f});

    tessellator->colorC(color);

    auto drawQuarterCircle = [&](const float startAngle, const float endAngle, const Vec2& center) {
        for (float angle = startAngle; angle < endAngle; angle += stepSize) {
            const float rad = angle * RAD_DEG;
            const float nextRad = (angle + stepSize) * RAD_DEG;

            const float sin1 = sinf(rad);
            const float sin2 = sinf(nextRad);
            const float cos1 = cosf(rad);
            const float cos2 = cosf(nextRad);

            tessellator->vertex(cos2 * offset + center.x, sin2 * offset + center.y, 0.f);
            tessellator->vertex(cos1 * offset + center.x, sin1 * offset + center.y, 0.f);
            tessellator->vertex(center.x, center.y, 0.f);
        }
    };

    if (flags & FLAG_CBR)
        drawQuarterCircle(0.f, 90.f, {pos.x + size.x - offset, pos.y + size.y - offset});

    if (flags & FLAG_CBL)
        drawQuarterCircle(90.f, 180.f, {pos.x + offset, pos.y + size.y - offset});

    if (flags & FLAG_CTL)
        drawQuarterCircle(180.f, 270.f, {pos.x + offset, pos.y + offset});

    if (flags & FLAG_CTR)
        drawQuarterCircle(270.f, 360.f, {pos.x + size.x - offset, pos.y + offset});
}