#include "PacketHooks.hpp"

#include "../../SDK/mc/common/network/Packet.hpp"
#include "../../SDK/mc/common/network/NetEventCallback.hpp"
#include "../../SDK/mc/common/network/NetworkIdentifier.hpp"
#include "../../SDK/mc/network/MinecraftPackets.hpp"

#include "../../SDK/SDK.hpp"
#include "../HookManager.hpp"
#include "../../Client/Event/EventManager.hpp"
#include "../../Client/Event/Events/PacketReceiveEvent.hpp"
#include "../../Client/Event/Events/PacketSendEvent.hpp"

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