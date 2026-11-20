#pragma once

#include "../../SDK/mc/client/renderer/MaterialPtr.h"

class MaterialStorage {
public:
    enum Material {
        ui_fill_color,
        ui_textured,
        particles_alpha
    };

    void init();
    mce::MaterialPtr* getMaterial(Material material);

private:
    std::unordered_map<Material, mce::MaterialPtr*> materials{};
};

extern MaterialStorage materialStorage;