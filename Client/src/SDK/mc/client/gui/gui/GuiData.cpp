#include "GuiData.hpp"

#include "../../../../../Offsets/OffsetManager.hpp"
#include "../../../../../Signatures/SigManager.hpp"

ScreenSizeData& GuiData::getScreenSizeData() {
    return hat::member_at<ScreenSizeData>(this, GET_OFFSET("GuiData::mcResolution"));
}

void GuiData::displayClientMessage(const std::string& message, std::optional<std::string> replaceWith, bool unknown) {
    static auto displayClientMessage = Memory::getFunction<&GuiData::displayClientMessage>(GET_SIGNATURE("GuiData::displayClientMessage"));
    (this->*displayClientMessage)(message, std::move(replaceWith), unknown);
}