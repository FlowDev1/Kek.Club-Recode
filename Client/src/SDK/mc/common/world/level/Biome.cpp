#include "Biome.h"

#include "../../../../../Offsets/OffsetManager.h"

int16_t Biome::getId() const {
    return hat::member_at<const int16_t>(this, GET_OFFSET("Biome::id"));
}

const HashedString& Biome::getName() const {
    return hat::member_at<const HashedString>(this, GET_OFFSET("Biome::name"));
}
