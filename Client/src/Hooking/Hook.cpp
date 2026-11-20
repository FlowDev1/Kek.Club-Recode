#include "Hook.h"

Hook::Hook(const uintptr_t targetFunction, const Function callbackFunction, const Type type) {
    this->targetFunction = reinterpret_cast<Function>(targetFunction);
    ClientAssert(MH_CreateHook(reinterpret_cast<Function>(targetFunction), callbackFunction, &trampolineFunction) == MH_OK, "MH_CreateHook returned a non-MH_OK status");
    this->callbackFunction = callbackFunction;
    this->type = type;
}

void Hook::enableHook() {
    ClientAssert(MH_EnableHook(targetFunction) == MH_OK, "MH_EnableHook returned a non-MH_OK status");
    isEnabled = true;
}

void Hook::disableHook() {
    ClientAssert(MH_DisableHook(targetFunction) == MH_OK, "MH_DisableHook returned a non-MH_OK status");
    isEnabled = false;
}

void Hook::enableHookQueued() {
    ClientAssert(MH_QueueEnableHook(targetFunction) == MH_OK, "MH_QueueEnableHook returned a non-MH_OK status");
    isEnabled = true;
}

void Hook::disableHookQueued() {
    ClientAssert(MH_QueueDisableHook(targetFunction) == MH_OK, "MH_QueueDisableHook returned a non-MH_OK status");
    isEnabled = false;
}

Hook::~Hook() {
    if (isEnabled)
        disableHook();
    ClientAssert(MH_RemoveHook(targetFunction) == MH_OK, "MH_RemoveHook returned a non-MH_OK status");
}