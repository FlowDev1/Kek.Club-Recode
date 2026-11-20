#include "ClientHooks.hpp"

#include "../HookManager.hpp"
#include "../../Client/Client.hpp"
#include "../../Signatures/SigManager.hpp"

#include "../../Client/Event/EventManager.hpp"
#include "../../Client/Event/Events/KeyEvent.hpp"
#include "../../Client/Event/Events/MouseEvent.hpp"

#include "../../SDK/mc/client/input/MouseDevice.hpp"

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