#pragma once

#include "mc/client/game/ClientInstance.h"
#include "mc/client/game/MainView.h"
#include "mc/client/gui/screens/ScreenView.h"
#include "mc/client/input/MouseDevice.h"
#include "mc/client/renderer/screen/MinecraftUIRenderContext.h"

class SDK {
public:
    static MainView* mainView;
    static Bedrock::Platform_UWP* platformUWP;
    static MinecraftGame* minecraftGame;
    static AppPlatform* appPlatform;
    static ClientInstance* clientInstance;
    static GuiData* guiData;
    static ScreenView* screenView;
    static MinecraftUIRenderContext* uiRenderContext;
    static ScreenContext* screenContext;
    static Tessellator* tessellator;
    static Minecraft* minecraft;
    static MouseDevice* mouseDevice;
    static LocalPlayer* localPlayer;

    static void init();
    static void update();
};