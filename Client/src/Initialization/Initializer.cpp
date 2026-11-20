#include "Initializer.h"

#include "../Client/Client.h"
#include "../Client/Command/CommandManager.h"
#include "../Client/Configs/ConfigManager.h"
#include "../Client/Module/ModuleManager.h"
#include "../SDK/mc/deps/core/mce/ServerTexture.h"
#include "../Hooking/HookManager.h"
#include "../SDK/SDK.h"
#include "../Signatures/SigManager.h"
#include "../Utils/Files.h"
#include "../Utils/Rendering/MaterialStorage.h"
#include "../Utils/Time.h"

DWORD WINAPI Initializer::ejectThread(LPVOID) {
    FreeLibraryAndExitThread(hinstDLL, 0);
}

void Initializer::initializeClient(const HMODULE hinstDLL) {
    Initializer::hinstDLL = hinstDLL;

    const auto startTime = Time::getCurrentTime();

    Files::init();
    Logger::initializeLogger();
    Logger::clearLogs();
    logF("Injecting client...");

    SigManager::addAllSignatures();
    sigMgr.scanAllSignatures();

    SDK::init();
    materialStorage.init();
    HookManager::initializeHooks();
    HookManager::toggleAllGlobalHooks(true);
    g_Client.subscribeEvents();
    Internationalization::setup();
    moduleMgr.initModules();
    commandMgr.initCommands();
    ConfigManager::initConfigManager();

    const auto endTime = Time::getCurrentTime();
    logF("Initialization took {} milliseconds", std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count());

    Utils::displayToastNotification("Recode", "Injected! (" + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()) + " milliseconds)", 3);
}

void Initializer::ejectClient() {
    logF("Uninjecting client...");

    ConfigManager::saveConfig(ConfigManager::currentConfig);

    g_Client.unsubscribeEvents();

    moduleMgr.disable();
    commandMgr.disable();
    HookManager::toggleAllGlobalHooks(false);
    HookManager::destroy();

    Utils::displayToastNotification("Recode", "Uninjected!", 3);

    CloseHandle(CreateThread(nullptr, 0, ejectThread, nullptr, 0, nullptr));
}