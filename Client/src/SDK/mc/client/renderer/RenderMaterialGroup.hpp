#pragma once

#include "MaterialPtr.hpp"
#include "../../deps/core/string/HashedString.hpp"

namespace mce {
    class RenderMaterialGroup {
    public:
        std::shared_ptr<MaterialPtr> getMaterial(const HashedString& name);
    };
}