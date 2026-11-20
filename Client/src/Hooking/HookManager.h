#pragma once

#include "Hook.h"

class HookManager {
public:
    static void initializeHooks();

    static void toggleAllGlobalHooks(bool enable);

    static Hook& getHook(Hook::Function func);

    template <typename... Args>
    static void addHook(Args&&... args) {
        auto hook = std::make_unique<Hook>(std::forward<Args>(args)...);
        const auto callback = hook->callbackFunction;
        hooks.emplace(callback, std::move(hook)); // even if 2nd arg gets evaluated first, we already copied the callback
    }

    template <auto callback>
    static decltype(auto) getReturn() {
        auto* const newCallback = reinterpret_cast<Hook::Function>(callback);
        return reinterpret_cast<decltype(callback)>(getHook(newCallback).trampolineFunction);
    }

    static void destroy();

private:
    static std::unordered_map<Hook::Function, std::unique_ptr<Hook>> hooks;
};