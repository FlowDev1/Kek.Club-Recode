#include "Font.hpp"

#include "../../../../../Utils/Memory.hpp"
#include "../../../../../Signatures/SigManager.hpp"

int Font::getLineLength(const std::string& str, float fontSize, bool showColorSymbol) {
    return Memory::callVFunc<6, &Font::getLineLength>(this, str, fontSize, showColorSymbol);
}

int Font::getTextHeight(const std::string& str, float fontSize) {
    static auto getTextHeight = Memory::getFunction<&Font::getTextHeight>(Memory::addressFromSigOffset(GET_SIGNATURE("Font::getTextHeight"), 1));
    return (this->*getTextHeight)(str, fontSize);
}