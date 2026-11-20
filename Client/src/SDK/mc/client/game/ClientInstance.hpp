#pragma once

#include "../../common/network/LoopbackPacketSender.hpp"
#include "IClientInstance.hpp"

#include "../../common/world/Minecraft.hpp"
#include "../../common/world/actor/player/LocalPlayer.hpp"
#include "../../deps/core/mce/Camera.hpp"
#include "../gui/gui/GuiData.hpp"

class ClientInstance : public IClientInstance {
public:
    Minecraft* getMinecraft();
    LoopbackPacketSender* getPacketSender();
    mce::Camera& getCamera();
    GuiData* getGuiData();
    LocalPlayer* getLocalPlayer();

    [[nodiscard]] bool isWorldActive() const;
};