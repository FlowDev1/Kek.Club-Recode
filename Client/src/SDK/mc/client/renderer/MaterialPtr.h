#pragma once

#include "../../deps/core/string/HashedString.h"

namespace mce {
    class MaterialPtr {
    public:
        static std::shared_ptr<MaterialPtr> getMaterial(const HashedString& name);
    };
}