#pragma once

#include "ScreenSizeData.h"

class GuiData {
public:
    ScreenSizeData& getScreenSizeData();
    void displayClientMessage(const std::string& message, std::optional<std::string> replaceWith = std::nullopt, bool unknown = false);
};