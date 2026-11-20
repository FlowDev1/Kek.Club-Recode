#pragma once

#include "Matrix.h"
#include "../../../../../Utils/Memory.h"

class MatrixStack {
public:
    struct MatrixStackRef {
        MatrixStack* stack;
        Matrix* mat;

        MatrixStackRef(MatrixStack* stack, Matrix* top) : stack(stack), mat(top) {}

        auto& operator->() const { return mat; }

        auto& operator*() const { return mat; }
    };

    std::stack<Matrix> stack{};
    Padding(0x10);
    bool isDirty{};

    MatrixStackRef push();
    void pop();
    Matrix& top();
};