#pragma once

#include "../../../../../Utils/VTableRef.hpp"

enum class Fonts {
    MinecraftTenEmoticon,
    MinecraftTen,
    DefaultFont,
    SmoothFontLatin,
    RuneFont,
    SmoothSmall,
    UIFont,
    OldSmoothFont,
    UnicodeFont,
    SmoothWithEmoticons
};

class Font : public std::enable_shared_from_this<Font> {
    VTableRef vTable{};

public:
    int getLineLength(const std::string& str, float fontSize = 1.f, bool showColorSymbol = false);
    int getTextHeight(const std::string& str, float fontSize = 0.f);
};