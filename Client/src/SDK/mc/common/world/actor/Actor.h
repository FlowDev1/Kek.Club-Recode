#pragma once

#include "ActorStatusProvider.h"

#include "../../../entity/EntityContext.h"

class Actor : public ActorStatusProvider {
    VTableRef vTable{};
public:
    EntityContext mEntityContext;
};