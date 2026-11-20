#include "MaterialPtr.h"

#include "RenderMaterialGroup.h"
#include "../../../../Utils/Memory.h"
#include "../../../../Signatures/SigManager.h"

std::shared_ptr<mce::MaterialPtr> mce::MaterialPtr::getMaterial(const HashedString& name) {
    static const auto signature = GET_SIGNATURE("mce::RenderMaterialGroup::common");
    if (!signature)
        return {};
    static auto* common = reinterpret_cast<RenderMaterialGroup*>(Memory::addressFromSigOffset(signature, 3));
    return common->getMaterial(name);
}