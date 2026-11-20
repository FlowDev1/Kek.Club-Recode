#pragma once

#define JM_XORSTR_DISABLE_AVX_INTRINSICS

#include <libhat/MemoryProtector.hpp>
#include <libhat/Scanner.hpp>

#include "Details.hpp"

#define FindSignature(szSignature)                                                                                     \
    ([]() {                                                                                                            \
        constexpr auto sig = hat::compile_signature<szSignature>();                                                    \
        return Memory::findSig(sig);                                                                            \
    })()

class Memory {
public:
    template <typename T>
    static T readMemory(const uintptr_t address) {
        return *reinterpret_cast<T*>(address);
    }

    static uintptr_t readPointer(uintptr_t ptrAddress, std::initializer_list<uintptr_t> offsets);

    static uintptr_t addressFromSigOffset(uintptr_t sig, size_t offset);

    static uint8_t getInstructionLength(uintptr_t address);

    static std::vector<std::byte> getBytes(uintptr_t addr);

    template<typename Fn, typename Inst, typename... Args>
    static decltype(auto) callMemberFunc(Inst* instance, const uintptr_t addr, Args&&... args) {
        // Translates 'R(Args...)' -> 'R(Inst::*)(Args...)' if needed
        using memfn_t = typename details::resolve_func<Fn>::template memfn_t<Inst>;

        const auto memfn = std::bit_cast<memfn_t>(addr);
        return (instance->*memfn)(std::forward<Args>(args)...);
    }
    // Following above and below function's are provided by Brady to the community
    template<size_t Index, typename Fn, typename Inst, typename... Args>
    static decltype(auto) callVFunc(Inst* instance, Args&&... args) {
        // This can be done numerous ways, this is the simplest for basic single-inheritance cases
        const auto vtable = *reinterpret_cast<uintptr_t* const*>(instance);

        return callMemberFunc<Fn>(instance, vtable[Index], std::forward<Args>(args)...);
    }

    template<auto Fn, typename Inst, typename... Args>
    static decltype(auto) callMemberFunc(Inst* instance, const uintptr_t addr, Args&&... args) {
        // Translates 'R(Args...)' -> 'R(Inst::*)(Args...)' if needed
        using memfn_t = typename details::resolve_func<decltype(Fn)>::template memfn_t<Inst>;

        const auto memfn = std::bit_cast<memfn_t>(addr);
        return (instance->*memfn)(std::forward<Args>(args)...);
    }

    template<size_t Index, auto Fn, typename Inst, typename... Args>
    static decltype(auto) callVFunc(Inst* instance, Args&&... args) {
        // This can be done numerous ways, this is the simplest for basic single-inheritance cases
        const auto vtable = *reinterpret_cast<uintptr_t* const*>(instance);

        return callMemberFunc<Fn>(instance, vtable[Index], std::forward<Args>(args)...);
    }

    template <auto fn, typename Func = decltype(fn)>
    static auto getFunction(uintptr_t function) {
        return *std::bit_cast<Func*>(&function);
    }

    static uintptr_t findSig(hat::signature_view signature);
};

#define MERGE(a, b) a##b
#define MERGE_(a, b) MERGE(a, b)
#define UNIQUE_IDENTIFIER MERGE_(unique_id_, __LINE__)
// Absolutely gaming code by brady for making padding/filler
#define Padding(size)                    \
private:                             \
uint8_t UNIQUE_IDENTIFIER[size]{}; \
public:


#define AS_FIELD(type, name, fn) __declspec(property(get = fn, put = set##name)) type name
#define DEF_FIELD_RW(type, name) __declspec(property(get = get##name, put = set##name)) type name

#define FAKE_FIELD(type, name)       \
AS_FIELD(type, name, get##name); \
type& get##name()
// I have no clue if replacing the direct_access with hat::member_at will break anything but we will find out eventually
#define BUILD_ACCESS(ptr, type, name, offset)                           \
AS_FIELD(type, name, get##name);                                    \
type& get##name() const { return hat::member_at<type>(ptr, offset); } \
void set##name(type v) const { hat::member_at<type>(ptr, offset) = std::move(v); }

#define CLASS_FIELD(type, name, offset)                                  \
AS_FIELD(type, name, get##name);                                     \
type& get##name() const { return hat::member_at<type>(this, offset); } \
void set##name(type v) const { hat::member_at<type>(this, offset) = std::move(v); }