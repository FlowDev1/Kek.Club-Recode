#include "SDK.h"

#include "../Signatures/SigManager.h"

#include "../Utils/Memory.h"
#include "../Utils/Text.h"

MainView* SDK::mainView = nullptr;
Bedrock::Platform_UWP* SDK::platformUWP = nullptr;
MinecraftGame* SDK::minecraftGame = nullptr;
AppPlatform* SDK::appPlatform = nullptr;
ClientInstance* SDK::clientInstance = nullptr;
GuiData* SDK::guiData = nullptr;
ScreenView* SDK::screenView = nullptr;
MinecraftUIRenderContext* SDK::uiRenderContext = nullptr;
ScreenContext* SDK::screenContext = nullptr;
Tessellator* SDK::tessellator = nullptr;
Minecraft* SDK::minecraft = nullptr;
MouseDevice* SDK::mouseDevice = nullptr;
LocalPlayer* SDK::localPlayer = nullptr;

void SDK::init() {
    mainView = *reinterpret_cast<MainView**>(Memory::addressFromSigOffset(GET_SIGNATURE("MainView::mInstance"), 3));
#ifndef NDEBUG
    ClientAssert(mainView, "The MainView pointer is null!");
#endif
    platformUWP = mainView->getPlatformUWP();
#ifndef NDEBUG
    ClientAssert(platformUWP, "The Platform_UWP pointer is null!");
#endif
    minecraftGame = platformUWP->getMinecraftGame();
#ifndef NDEBUG
    ClientAssert(minecraftGame, "The MinecraftGame pointer is null!");
#endif
    appPlatform = platformUWP->getAppPlatform();
#ifndef NDEBUG
    ClientAssert(appPlatform, "The AppPlatform pointer is null!");
#endif
    clientInstance = reinterpret_cast<ClientInstance*>(minecraftGame->getClientInstances()[0].get());
#ifndef NDEBUG
    ClientAssert(clientInstance, "The ClientInstance pointer is null!");
#endif

    guiData = clientInstance->getGuiData();
    minecraft = clientInstance->getMinecraft();
    mouseDevice = reinterpret_cast<MouseDevice*>(Memory::addressFromSigOffset(GET_SIGNATURE("Mouse::_instance"), 3));
    localPlayer = clientInstance->getLocalPlayer();

#ifndef NDEBUG
    logF("MainView: {}", Text::toHexAddress(mainView));
    logF("Platform_UWP: {}", Text::toHexAddress(platformUWP));
    logF("MinecraftGame: {}", Text::toHexAddress(minecraftGame));
    logF("AppPlatform: {}", Text::toHexAddress(appPlatform));
    logF("ClientInstance: {}", Text::toHexAddress(clientInstance));
    logF("GuiData: {}", Text::toHexAddress(guiData));
    logF("Minecraft: {}", Text::toHexAddress(minecraft));
    logF("MouseDevice: {}", Text::toHexAddress(mouseDevice));
    logF("LocalPlayer: {}", Text::toHexAddress(localPlayer));
#endif
}

void SDK::update() {
    localPlayer = clientInstance->getLocalPlayer();
}