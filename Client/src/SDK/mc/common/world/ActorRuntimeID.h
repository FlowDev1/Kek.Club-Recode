#pragma once

class ActorRuntimeID {
public:
    uint64_t rawID;

    [[nodiscard]] constexpr ActorRuntimeID() : rawID(0) {}
    [[nodiscard]] constexpr explicit ActorRuntimeID(const uint64_t x) : rawID(x) {}

    [[nodiscard]] constexpr explicit operator uint64_t() const { return rawID; }
};

namespace std {
    template <>
    class hash<ActorRuntimeID> {
    public:
        size_t operator()(ActorRuntimeID const& id) const noexcept { return std::hash<int64_t>()(id.rawID); }
    };
}