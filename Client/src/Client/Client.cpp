#include "Client.h"

#include "../Initialization/Initializer.h"
#include "../SDK/SDK.h"
#include "../Utils/Time.h"
#include "Event/EventManager.h"

bool Client::isKeyDown(const unsigned char key) const {
    return this->keys[key];
}

void Client::subscribeEvents() {
    eventMgr.subscribe<&Client::onKeyUpdate>(this);
    eventMgr.subscribe<&Client::onGameTick>(this);
    eventMgr.subscribe<&Client::onClientTick>(this);
}

void Client::unsubscribeEvents() {
    eventMgr.unsubscribe<&Client::onKeyUpdate>(this);
    eventMgr.unsubscribe<&Client::onGameTick>(this);
    eventMgr.unsubscribe<&Client::onClientTick>(this);
}

void Client::onKeyUpdate(KeyEvent&) const {
    if ((this->isKeyDown(VK_CONTROL) && this->isKeyDown('L')) || this->isKeyDown(VK_END)) {
        Initializer::isRunning = false;
        (void)ApplicationModel::Core::CoreApplication::MainView().CoreWindow().Dispatcher().RunAsync(UI::Core::CoreDispatcherPriority::Normal, &Initializer::ejectClient);
    }
}

void Client::onGameTick(const GameTickEvent&) {
    if (SDK::guiData == nullptr || !SDK::clientInstance->isWorldActive())
        return;

    for (const auto& [log, level] : Logger::logsToPrint) {
        if (level == Logger::Level::Info)
            SDK::guiData->displayClientMessage(log);
        else if (level == Logger::Level::Debug) {
            const std::string formatted = fmt::format("{}{}{} {}", ColorFormat::GOLD, Time::getTimestamp(), ColorFormat::RESET, log);
            SDK::guiData->displayClientMessage(formatted);
        }
    }
    Logger::logsToPrint.clear();
}

void Client::onClientTick(const ClientTickEvent&) {
    SDK::update();
}

Client g_Client;