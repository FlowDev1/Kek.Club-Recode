#pragma once

#include <libhat/Signature.hpp>

struct Signature {
    hat::signature signature;
    uintptr_t address = 0;
    bool scanned = false;

    template <size_t N>
    explicit Signature(hat::fixed_signature<N> signature) : signature(signature.begin(), signature.end()) {}

    template <hat::fixed_string str>
    static Signature create() {
        return Signature(hat::compile_signature<str>());
    }
};