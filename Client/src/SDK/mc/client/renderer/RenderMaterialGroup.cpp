#include "RenderMaterialGroup.h"

#include "../../../../Utils/Memory.h"

mce::MaterialPtr* mce::RenderMaterialGroup::getMaterial(const HashedString& name) {
    return Memory::callVFunc<1, &RenderMaterialGroup::getMaterial>(this, name);
}