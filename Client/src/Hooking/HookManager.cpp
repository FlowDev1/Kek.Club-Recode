#include "HookManager.h"

#include "Hooks/ClientHooks.h"
#include "Hooks/PacketHooks.h"
#include "Hooks/ScreenHooks.h"
#include "Hooks/TickHooks.h"

std::unordered_map<Hook::Function, std::unique_ptr<Hook>> HookManager::hooks{};

void HookManager::initializeHooks() {
    ScreenHooks::addScreenHooks();
    ClientHooks::addClientHooks();
    TickHooks::addTickHooks();
    PacketHooks::addPacketHooks();
}

void HookManager::toggleAllGlobalHooks(const bool enable) {
    for (const auto& hook : std::views::values(hooks)) {
        if (hook->type == Hook::Type::Global)
            enable ? hook->enableHook() : hook->disableHook();
    }
}

Hook& HookManager::getHook(const Hook::Function func) {
    ClientAssert(hooks.contains(func), "Invalid function!");
    return *hooks[func].get();
}

void HookManager::destroy() {
    hooks.clear();
}