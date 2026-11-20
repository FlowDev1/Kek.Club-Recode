#pragma once

#include "../../../deps/core/string/HashedString.hpp"

class Biome {
public:
    [[nodiscard]] int16_t getId() const;
    [[nodiscard]] const HashedString& getName() const;
};
