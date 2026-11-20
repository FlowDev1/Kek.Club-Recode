#pragma once

#include "Font.h"

#include "../../../deps/application/AppPlatformListener.h"
#include "../../../deps/core/common/bedrock/EnableNonOwnerReferences.h"

class FontRepository : public AppPlatformListener, public Bedrock::EnableNonOwnerReferences {
    bool isInitialized{};
    std::vector<std::shared_ptr<Font>> loadedFonts;
    std::unordered_map<std::string, uint64_t> fontNameToIdentifier;

    uint64_t getFontIdentifier(const std::string& fontName);

public:
    Font* getFont(Fonts font);
};