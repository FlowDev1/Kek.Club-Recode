#pragma once

#include "Signature.h"
#include "../Utils/Memory.h"
#include "../Utils/Math/Math.h"

#define ADD_SIGNATURE(name, sig) sigMgr.addSignature<name>(Signature::create<sig>())
#define GET_SIGNATURE(name) sigMgr.getSignature<name>()

class SigManager {
public:
    template <hat::fixed_string name>
    constexpr void addSignature(Signature&& sig) {
        const auto failed = signatures.emplace(Math::compile_time_hash(name.to_view()), std::move(sig));
        ClientAssert(failed.second, "Failed to add signature");
    }

    template <hat::fixed_string name>
    constexpr uintptr_t getSignature() {
        Signature& sig = signatures.at(Math::compile_time_hash(name.to_view()));

        if (sig.address == 0 && !sig.scanned) {
            sig.address = Memory::findSig(sig.signature);
            sig.scanned = true;
        }

        return sig.address;
    }

    void scanAllSignatures();

    static void addAllSignatures();

private:
    std::unordered_map<size_t, Signature> signatures{};
};

extern SigManager sigMgr;