#pragma once

#include "../../common/network/LoopbackPacketSender.h"
#include "IClientInstance.h"

#include "../../common/world/Minecraft.h"
#include "../../common/world/actor/player/LocalPlayer.h"
#include "../../deps/core/mce/Camera.h"
#include "../gui/gui/GuiData.h"

class ClientInstance : public IClientInstance {
public:
    Minecraft* getMinecraft();
    LoopbackPacketSender* getPacketSender();
    mce::Camera& getCamera();
    GuiData* getGuiData();
    LocalPlayer* getLocalPlayer();

    [[nodiscard]] bool isWorldActive() const;
};