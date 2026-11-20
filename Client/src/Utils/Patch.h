#pragma once

class Patch {
public:
    Patch(uintptr_t addr, std::initializer_list<std::byte> newBytes, bool enable = true);

    explicit Patch(uintptr_t addr, bool enable = true);

    void enable() const;

    void disable() const;

    ~Patch();

private:
    enum Type {
        Nop,
        // Ret, hooking is better for this
        Normal
    };

    Type type = Normal;
    uintptr_t address = 0;
    std::vector<std::byte> originalBytes;
    std::vector<std::byte> desiredBytes;
};