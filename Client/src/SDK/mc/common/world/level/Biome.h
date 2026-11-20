#pragma once

#include "../../../deps/core/string/HashedString.h"

class Biome {
public:
    [[nodiscard]] int16_t getId() const;
    [[nodiscard]] const HashedString& getName() const;
};
