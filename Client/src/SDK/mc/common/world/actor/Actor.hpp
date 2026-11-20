#pragma once

#include "ActorStatusProvider.hpp"

#include "../../../entity/EntityContext.hpp"

class Actor : public ActorStatusProvider {
    VTableRef vTable{};
public:
    EntityContext mEntityContext;
};