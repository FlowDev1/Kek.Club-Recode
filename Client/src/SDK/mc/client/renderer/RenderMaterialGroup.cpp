#include "RenderMaterialGroup.hpp"

#include "../../../../Utils/Memory.hpp"

std::shared_ptr<mce::MaterialPtr> mce::RenderMaterialGroup::getMaterial(const HashedString& name) {
    return Memory::callVFunc<1, &RenderMaterialGroup::getMaterial>(this, name);
}