#pragma once

#include "Font.hpp"

#include "../../../deps/application/AppPlatformListener.hpp"
#include "../../../deps/core/common/bedrock/EnableNonOwnerReferences.hpp"

class FontRepository : public AppPlatformListener, public Bedrock::EnableNonOwnerReferences {
    bool isInitialized{};
    std::vector<std::shared_ptr<Font>> loadedFonts;
    std::unordered_map<std::string, uint64_t> fontNameToIdentifier;

    uint64_t getFontIdentifier(const std::string& fontName);

public:
    Font* getFont(Fonts font);
};