#pragma once

#include "../../../../Utils/VTableRef.h"
#include "../../deps/core/common/bedrock/EnableNonOwnerReferences.h"

class NetEventCallback : public Bedrock::EnableNonOwnerReferences {
    VTableRef vTable{};
};