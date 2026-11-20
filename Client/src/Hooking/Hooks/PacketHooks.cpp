#include "PacketHooks.h"

#include "../../SDK/mc/common/network/Packet.h"
#include "../../SDK/mc/common/network/NetEventCallback.h"
#include "../../SDK/mc/common/network/NetworkIdentifier.h"
#include "../../SDK/mc/network/MinecraftPackets.h"

#include "../../SDK/SDK.h"
#include "../HookManager.h"
#include "../../Client/Event/EventManager.h"
#include "../../Client/Event/Events/PacketReceiveEvent.h"
#include "../../Client/Event/Events/PacketSendEvent.h"

namespace {
    template <MinecraftPacketIds PacketId>
    void PacketHandlerDispatcherInstance_handle(const IPacketHandlerDispatcher* _this, const NetworkIdentifier& source, NetEventCallback& callback, std::shared_ptr<Packet>& packet) {
        static auto oFunc = HookManager::getReturn<&PacketHandlerDispatcherInstance_handle<PacketId>>();
        const bool isClientHandler = SDK::minecraft->getGameSession()->getClientNetworkHandler().get() == &callback;

        if (isClientHandler) {
            PacketReceiveEvent event(packet.get());
            eventMgr.emit(event);
            if (event.isCancelled())
                return;
        }

        oFunc(_this, source, callback, packet);
    }

    void LoopbackPacketSender_sendToServer(LoopbackPacketSender* _this, Packet& packet) {
        static auto oFunc = HookManager::getReturn<&LoopbackPacketSender_sendToServer>();

        PacketSendEvent event(packet);
        eventMgr.emit(event);
        if (event.isCancelled())
            return;

        oFunc(_this, packet);
    }
}

void PacketHooks::addPacketHooks() {
    magic_enum::enum_for_each<MinecraftPacketIds>([](auto id) {
        constexpr MinecraftPacketIds pid = id;
        HookManager::addHook(MinecraftPackets::createPacket(pid)->handler->vTable[1], PacketHandlerDispatcherInstance_handle<pid>);
    });
    HookManager::addHook(SDK::clientInstance->getPacketSender()->vTable[2], LoopbackPacketSender_sendToServer);
}