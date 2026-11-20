#pragma once

#include "ScreenContext.hpp"
#include "TextMeasureData.hpp"
#include "UIRenderContext.hpp"
#include "CaretMeasureData.hpp"
#include "../../gui/UITypes.hpp"
#include "../../gui/gui/Font.hpp"
#include "../../../deps/core/mce/Color.hpp"
#include "../../../deps/core/mce/TexturePtr.hpp"
#include "../../../../../Utils/Math/Vectors.hpp"

class MinecraftUIRenderContext : public UIRenderContext {
public:
    ScreenContext* getScreenContext();

    void drawText(Font& font, const RectangleArea& pos, const std::string& text, const mce::Color& color = mce::Color(), float alpha = 1, ui::TextAlignment textAlignment = ui::TextAlignment::Left, const TextMeasureData& textData = TextMeasureData(), const CaretMeasureData& caretData = CaretMeasureData());
    void flushText(float deltaTime, std::optional<float> unknown = std::nullopt);
    void drawRectangle(const RectangleArea& rect, const mce::Color& color, float alpha, int thickness);
    void fillRectangle(const RectangleArea& rect, const mce::Color& color, float alpha);
    mce::TexturePtr getTexture(ResourceLocation& resourceLocation, bool forceReload) const;
};