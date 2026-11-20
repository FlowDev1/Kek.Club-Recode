#include "ClientHooks.h"

#include "../HookManager.h"
#include "../../Client/Client.h"
#include "../../Signatures/SigManager.h"

#include "../../Client/Event/EventManager.h"
#include "../../Client/Event/Events/KeyEvent.h"
#include "../../Client/Event/Events/MouseEvent.h"

#include "../../SDK/mc/client/input/MouseDevice.h"

namespace {
    void Keyboard_feed(unsigned char keyCode, int state) {
        static auto oFunc = HookManager::getReturn<&Keyboard_feed>();

        g_Client.keys[keyCode] = state != 0;

        KeyEvent event(keyCode, state != 0);
        eventMgr.emit(event);
        if (event.isCancelled())
            return;

        oFunc(keyCode, state);
    }

    void MouseDevice_feed(MouseDevice* _this, char actionButtonId, int8_t buttonData, int16_t x, int16_t y, int16_t dx, int16_t dy, bool forceMotionlessPointer) {
        static auto oFunc = HookManager::getReturn<&MouseDevice_feed>();

        MouseEvent event(actionButtonId, buttonData, x, y);
        eventMgr.emit(event);
        if (event.isCancelled())
            return;

        oFunc(_this, actionButtonId, buttonData, x, y, dx, dy, forceMotionlessPointer);
    }
}

void ClientHooks::addClientHooks() {
    HookManager::addHook(GET_SIGNATURE("Keyboard::feed"), Keyboard_feed);
    HookManager::addHook(Memory::addressFromSigOffset(GET_SIGNATURE("MouseDevice::feed"), 1), MouseDevice_feed);
}