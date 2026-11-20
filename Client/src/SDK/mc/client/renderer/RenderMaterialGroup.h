#pragma once

#include "MaterialPtr.h"
#include "../../deps/core/string/HashedString.h"

namespace mce {
    class RenderMaterialGroup {
    public:
        std::shared_ptr<MaterialPtr> getMaterial(const HashedString& name);
    };
}