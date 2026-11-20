#include "MinecraftGame.h"

std::map<uint8_t, std::shared_ptr<IClientInstance>>& MinecraftGame::getClientInstances() {
    return hat::member_at<std::map<uint8_t, std::shared_ptr<IClientInstance>>>(this, 0x938);
}

FontRepository* MinecraftGame::getFontRepository() {
    return hat::member_at<std::shared_ptr<FontRepository>>(this, 0x178).get();
}