#pragma once

struct Tick {
public:
    uint64_t tickID;

    [[nodiscard]] constexpr Tick(uint64_t id) : tickID(id){};
    [[nodiscard]] constexpr Tick() : tickID(0){};
};