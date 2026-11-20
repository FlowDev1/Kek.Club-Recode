#include "Memory.hpp"

#include <Zydis/Zydis.h>

uintptr_t Memory::readPointer(const uintptr_t ptrAddress, const std::initializer_list<uintptr_t> offsets) {
    uintptr_t result = ptrAddress;
    for (const uintptr_t offset : offsets)
        result = readMemory<uintptr_t>(result + offset);

    return result;
}

uintptr_t Memory::addressFromSigOffset(const uintptr_t sig, const size_t offset) {
    auto* const start = reinterpret_cast<std::byte*>(sig);
    return reinterpret_cast<uintptr_t>(hat::scan_result(start).rel(offset));
}

uint8_t Memory::getInstructionLength(const uintptr_t address) {
    ZydisDisassembledInstruction instruction;
    ZydisDisassembleIntel(ZYDIS_MACHINE_MODE_LONG_64, address, reinterpret_cast<void*>(address), 15, &instruction);
    return instruction.info.length; // Cool way to auto get instruction size
}

std::vector<std::byte> Memory::getBytes(const uintptr_t addr) {
    std::vector<std::byte> bytes;
    const uint8_t distance = getInstructionLength(addr);
    bytes.resize(distance);

    const hat::memory_protector protector(addr, distance, hat::protection::Read);
    memcpy(bytes.data(), reinterpret_cast<void*>(addr), distance);
    return bytes;
}

uintptr_t Memory::findSig(const hat::signature_view signature) {
    const auto result = find_pattern(signature, xorstr(".text"));
    /* This code can be used when updating to find the amount of results (fonctions) each signature returns
    static auto section = hat::process::get_process_module().get_section_data(".text");
    const auto results = find_all_pattern(section, signature);
#ifndef NDEBUG
    logF("Signature [{}] has {} results", Logger::convertSigViewToString(signature), results.size());
#endif */
    if (result.has_result())
        return reinterpret_cast<uintptr_t>(result.get());

#ifndef NDEBUG
    logF("Signature dead: {}", Logger::convertSigViewToString(signature));
#endif
    return 0;
}