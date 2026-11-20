#pragma once

#include "../../network/IPacketHandlerDispatcher.h"
#include "../../network/NetworkPeer.h"
#include "../../resources/PacketPriority.h"

#include "../../enums/Compressibility.h"
#include "../../enums/MinecraftPacketIds.h"
#include "../../enums/SubClientId.h"

class Packet {
public:
    VTableRef vTable{}; // 0x0
private:
    PacketPriority priority = PacketPriority::MediumPriority; // 0x8
    NetworkPeer::Reliability reliability = NetworkPeer::Reliability::ReliableOrdered; // 0xC
    SubClientId clientSubId = SubClientId::PrimaryClient; // 0x10
    bool isHandled = false; // 0x11
    NetworkPeer::PacketRecvTimepoint receiveTimepoint; // 0x18
public:
    const IPacketHandlerDispatcher* handler = nullptr; // 0x20
private:
    Compressibility compressible = Compressibility::Compressible; // 0x28

public:
    [[nodiscard]] MinecraftPacketIds getId() const;
    [[nodiscard]] std::string getName() const;
};