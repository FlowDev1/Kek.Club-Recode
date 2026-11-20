#pragma once

struct TextMeasureData {
    const float fontSize;
    const float linePadding;
    const bool renderShadow;
    const bool showColorSymbol;
    const bool hideHyphen;

    explicit TextMeasureData(const float fontSize = 1, const float linePadding = 0, const bool renderShadow = false, const bool showColorSymbol = true, const bool hideHyphen = false) : fontSize(fontSize), linePadding(linePadding), renderShadow(renderShadow), showColorSymbol(showColorSymbol), hideHyphen(hideHyphen) {}
};