#pragma once

#include "../../common/certificates/Certificate.h"
#include "../../common/network/NetworkIdentifier.h"
#include "../../common/world/ECS/IEntityComponent.h"
#include "../../deps/core/mce/UUID.h"
#include "../../enums/SubClientId.h"

class UserEntityIdentifierComponent : IEntityComponent {
public:
    NetworkIdentifier networkId; // 0x0
    SubClientId clientSubId; // 0xA0
    mce::UUID clientUUID; // 0xA8
    std::string playFabId; // 0xB8
    std::unique_ptr<Certificate> certificate; // 0xD8
};