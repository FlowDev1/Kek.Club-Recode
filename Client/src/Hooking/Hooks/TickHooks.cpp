#include "TickHooks.h"

#include "../../Signatures/SigManager.h"
#include "../../Utils/Memory.h"
#include "../HookManager.h"

#include "../../Client/Event/EventManager.h"
#include "../../Client/Event/Events/ClientTickEvent.h"
#include "../../Client/Event/Events/GameTickEvent.h"
#include "../../SDK/SDK.h"

namespace {
    void Minecraft_tick(Minecraft* _this) {
        static auto oFunc = HookManager::getReturn<&Minecraft_tick>();

        if (_this == SDK::minecraft) {
            GameTickEvent event;
            eventMgr.emit(event);
        }

        oFunc(_this);
    }

    bool ClientInstance_update(ClientInstance* _this, bool isInitFinished) {
        static auto oFunc = HookManager::getReturn<&ClientInstance_update>();

        ClientTickEvent event;
        eventMgr.emit(event);

        return oFunc(_this, isInitFinished);
    }
}

void TickHooks::addTickHooks() {
    HookManager::addHook(Memory::addressFromSigOffset(GET_SIGNATURE("Minecraft::tick"), 1), Minecraft_tick);
    HookManager::addHook(GET_SIGNATURE("ClientInstance::update"), ClientInstance_update);
}