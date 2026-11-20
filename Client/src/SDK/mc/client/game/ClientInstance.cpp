#include "ClientInstance.h"

Minecraft* ClientInstance::getMinecraft() {
    return hat::member_at<std::unique_ptr<Minecraft>>(this, 0xD8).get();
}

LoopbackPacketSender* ClientInstance::getPacketSender() {
    return hat::member_at<std::unique_ptr<LoopbackPacketSender>>(this, 0xF8).get();
}

mce::Camera& ClientInstance::getCamera() {
    return hat::member_at<mce::Camera>(this, 0x2A8);
}

GuiData* ClientInstance::getGuiData() {
    return hat::member_at<std::unique_ptr<GuiData>>(this, 0x590).get();
}

LocalPlayer* ClientInstance::getLocalPlayer() {
    return Memory::callVFunc<30, &ClientInstance::getLocalPlayer>(this);
}

bool ClientInstance::isWorldActive() const {
    return Memory::callVFunc<180, &ClientInstance::isWorldActive>(this); // Maybe
}