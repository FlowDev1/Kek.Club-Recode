#pragma once

#include "../../SDK/mc/client/renderer/MaterialPtr.hpp"

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
    std::unordered_map<Material, std::shared_ptr<mce::MaterialPtr>> materials{};
};

extern MaterialStorage materialStorage;