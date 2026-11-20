#pragma once

namespace mce {
    struct UUID {
        uint64_t mostSignificant;
        uint64_t leastSignificant;

        constexpr UUID() : mostSignificant(0), leastSignificant(0) {}
        constexpr UUID(const uint64_t mostSignificant, const uint64_t leastSignificant) : mostSignificant(mostSignificant), leastSignificant(leastSignificant) {}

        bool operator==(const UUID& other) const { return mostSignificant == other.mostSignificant && leastSignificant == other.leastSignificant; }

        UUID& operator=(const UUID& other) {
            if (this != &other) {
                mostSignificant = other.mostSignificant;
                leastSignificant = other.leastSignificant;
            }
            return *this;
        }
    };
}

namespace std {
    template <>
    struct hash<mce::UUID> {
        size_t operator()(mce::UUID const& id) const noexcept { return id.mostSignificant ^ (522133279 * id.leastSignificant); }
    };
}