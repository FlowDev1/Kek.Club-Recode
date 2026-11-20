#pragma once

#include "../../../../Utils/VTableRef.hpp"
#include "../../deps/core/common/bedrock/EnableNonOwnerReferences.hpp"

class NetEventCallback : public Bedrock::EnableNonOwnerReferences {
    VTableRef vTable{};
};