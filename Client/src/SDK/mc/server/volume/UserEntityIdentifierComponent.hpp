#pragma once

#include "../../common/certificates/Certificate.hpp"
#include "../../common/network/NetworkIdentifier.hpp"
#include "../../common/world/ECS/IEntityComponent.hpp"
#include "../../deps/core/mce/UUID.hpp"
#include "../../enums/SubClientId.hpp"

class UserEntityIdentifierComponent : IEntityComponent {
public:
    NetworkIdentifier networkId; // 0x0
    SubClientId clientSubId; // 0xA0
    mce::UUID clientUUID; // 0xA8
    std::string playFabId; // 0xB8
    std::unique_ptr<Certificate> certificate; // 0xD8
};