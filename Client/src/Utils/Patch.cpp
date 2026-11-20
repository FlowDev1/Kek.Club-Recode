#include "Patch.hpp"

#include <libhat/MemoryProtector.hpp>

#include "Logger.hpp"
#include "Memory.hpp"

Patch::Patch(const uintptr_t addr, const std::initializer_list<std::byte> newBytes, const bool enable) {
    this->address = addr;
    this->type = Normal;
    this->desiredBytes = newBytes;
    this->originalBytes = Memory::getBytes(addr);

    if (enable)
        this->enable();
}

Patch::Patch(const uintptr_t addr, const bool enable) {
    this->address = addr;
    this->type = Nop;
    this->originalBytes = Memory::getBytes(addr);
    const uint8_t size = Memory::getInstructionLength(addr);
    this->desiredBytes = std::vector(size, static_cast<std::byte>(0x90));

    if (enable)
        this->enable();
}

void Patch::enable() const {
    ClientAssert(Memory::getBytes(address) != desiredBytes, "Patch is already enabled");
    hat::memory_protector protector(address, desiredBytes.size(), hat::protection::Read | hat::protection::Write | hat::protection::Execute);
    memcpy(reinterpret_cast<void*>(address), desiredBytes.data(), desiredBytes.size());
}

void Patch::disable() const {
    ClientAssert(Memory::getBytes(address) != originalBytes, "Patch is already disabled");
    hat::memory_protector protector(address, originalBytes.size(), hat::protection::Read | hat::protection::Write | hat::protection::Execute);
    memcpy(reinterpret_cast<void*>(address), originalBytes.data(), originalBytes.size());
}

Patch::~Patch() {
    ClientAssert(Memory::getBytes(address) == originalBytes, "Patch was not disabled properly");
}