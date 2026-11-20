#pragma once

struct VTableRef {
    uintptr_t* vtable = nullptr;

    uintptr_t operator[](const size_t index) const {
        return vtable[index];
    }
};