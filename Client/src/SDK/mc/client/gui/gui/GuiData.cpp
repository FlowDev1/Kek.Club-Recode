#include "GuiData.h"

#include "../../../../../Signatures/SigManager.h"

ScreenSizeData& GuiData::getScreenSizeData() {
    return hat::member_at<ScreenSizeData>(this, 0x30);
}

void GuiData::displayClientMessage(const std::string& message, std::optional<std::string> replaceWith, bool unknown) {
    static auto displayClientMessage = Memory::getFunction<&GuiData::displayClientMessage>(GET_SIGNATURE("GuiData::displayClientMessage"));
    (this->*displayClientMessage)(message, std::move(replaceWith), unknown);
}