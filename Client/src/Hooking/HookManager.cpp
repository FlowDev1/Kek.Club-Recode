#include "HookManager.hpp"

#include "Hooks/ClientHooks.hpp"
#include "Hooks/PacketHooks.hpp"
#include "Hooks/ScreenHooks.hpp"
#include "Hooks/TickHooks.hpp"

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