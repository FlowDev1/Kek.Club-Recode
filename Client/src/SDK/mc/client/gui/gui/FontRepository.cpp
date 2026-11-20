#include "FontRepository.hpp"

uint64_t FontRepository::getFontIdentifier(const std::string& fontName) {
    return fontNameToIdentifier[fontName];
}

Font* FontRepository::getFont(const Fonts font) {
    const auto fontName = magic_enum::enum_name(font);
    const auto identifier = this->getFontIdentifier(std::string(fontName));
    return loadedFonts[identifier].get();
}