#pragma once

#include "ScreenContext.h"
#include "TextMeasureData.h"
#include "UIRenderContext.h"
#include "CaretMeasureData.h"
#include "../../gui/UITypes.h"
#include "../../gui/gui/Font.h"
#include "../../../deps/core/mce/Color.h"
#include "../../../deps/core/mce/TexturePtr.h"
#include "../../../../../Utils/Math/Vectors.h"

class MinecraftUIRenderContext : public UIRenderContext {
public:
    ScreenContext* getScreenContext();

    void drawText(Font& font, const RectangleArea& pos, const std::string& text, const mce::Color& color = mce::Color(), float alpha = 1, ui::TextAlignment textAlignment = ui::TextAlignment::Left, const TextMeasureData& textData = TextMeasureData(), const CaretMeasureData& caretData = CaretMeasureData());
    void flushText(float deltaTime, std::optional<float> unknown = std::nullopt);
    void drawRectangle(const RectangleArea& rect, const mce::Color& color, float alpha, int thickness);
    void fillRectangle(const RectangleArea& rect, const mce::Color& color, float alpha);
    mce::TexturePtr getTexture(ResourceLocation& resourceLocation, bool forceReload) const;
};