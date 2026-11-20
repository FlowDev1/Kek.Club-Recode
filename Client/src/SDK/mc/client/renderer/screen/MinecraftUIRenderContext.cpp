#include "MinecraftUIRenderContext.hpp"

#include "../../../../../Utils/Memory.hpp"

ScreenContext* MinecraftUIRenderContext::getScreenContext() {
    return hat::member_at<ScreenContext*>(this, 0x10); // It is a reference, but libhat currently does not support that
}

void MinecraftUIRenderContext::drawText(Font& font, const RectangleArea& pos, const std::string& text, const mce::Color& color, float alpha, ui::TextAlignment textAlignment, const TextMeasureData& textData, const CaretMeasureData& caretData) {
    Memory::callVFunc<5, &MinecraftUIRenderContext::drawText>(this, font, pos, text, color, alpha, textAlignment, textData, caretData);
}

void MinecraftUIRenderContext::flushText(float deltaTime, std::optional<float> unknown) {
    Memory::callVFunc<6, &MinecraftUIRenderContext::flushText>(this, deltaTime, unknown);
}

void MinecraftUIRenderContext::drawRectangle(const RectangleArea& rect, const mce::Color& color, float alpha, int thickness) {
    Memory::callVFunc<12, &MinecraftUIRenderContext::drawRectangle>(this, rect, color, alpha, thickness);
}

void MinecraftUIRenderContext::fillRectangle(const RectangleArea& rect, const mce::Color& color, float alpha) {
    Memory::callVFunc<13, &MinecraftUIRenderContext::fillRectangle>(this, rect, color, alpha);
}

mce::TexturePtr MinecraftUIRenderContext::getTexture(ResourceLocation& resourceLocation, bool forceReload) const {
    return Memory::callVFunc<29, &MinecraftUIRenderContext::getTexture>(this, resourceLocation, forceReload);
}