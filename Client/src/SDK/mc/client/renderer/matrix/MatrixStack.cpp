#include "MatrixStack.hpp"

MatrixStack::MatrixStackRef MatrixStack::push() {
    this->isDirty = true;

    const auto latest = this->stack.top();
    this->stack.emplace(latest);

    return {this, &this->stack.top()};
}

void MatrixStack::pop() {
    this->isDirty = true;
    this->stack.pop();
}

Matrix& MatrixStack::top() {
    return this->stack.top();
}