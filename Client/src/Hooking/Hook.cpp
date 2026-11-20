#include "Hook.hpp"

Hook::Hook(const uintptr_t targetFunction, const Function callbackFunction, const Type type)
    : handle(safetyhook::InlineHook::create(reinterpret_cast<Function>(targetFunction), callbackFunction,
          safetyhook::InlineHook::StartDisabled).value()),
      type(type), callbackFunction(callbackFunction) {}

void Hook::enableHook() {
    handle.enable().value();
}

void Hook::disableHook() {
    handle.disable().value();
}
