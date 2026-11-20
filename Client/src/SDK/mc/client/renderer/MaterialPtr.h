#pragma once

#include "../../deps/core/string/HashedString.h"

namespace mce {
    class MaterialPtr {
    public:
        static MaterialPtr* getMaterial(const HashedString& name);
    };
}