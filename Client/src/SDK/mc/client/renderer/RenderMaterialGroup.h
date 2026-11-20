#pragma once

#include "MaterialPtr.h"
#include "../../deps/core/string/HashedString.h"

namespace mce {
    class RenderMaterialGroup {
    public:
        MaterialPtr* getMaterial(const HashedString& name);
    };
}