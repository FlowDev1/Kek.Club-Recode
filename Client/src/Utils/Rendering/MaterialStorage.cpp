#include "MaterialStorage.h"

void MaterialStorage::init() {
    magic_enum::enum_for_each<Material>([this](const Material material) {
        materials.emplace(material, mce::MaterialPtr::getMaterial(magic_enum::enum_name(material)));
    });
}

mce::MaterialPtr* MaterialStorage::getMaterial(const Material material) {
    return materials[material].get();
}

MaterialStorage materialStorage;