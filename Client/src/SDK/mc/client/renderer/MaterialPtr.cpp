#include "MaterialPtr.h"

#include "RenderMaterialGroup.h"
#include "../../../../Utils/Memory.h"
#include "../../../../Signatures/SigManager.h"

mce::MaterialPtr* mce::MaterialPtr::getMaterial(const HashedString& name) {
    static auto common = reinterpret_cast<RenderMaterialGroup*>(Memory::addressFromSigOffset(GET_SIGNATURE("mce::RenderMaterialGroup::common"), 3));
    return common->getMaterial(name);
}