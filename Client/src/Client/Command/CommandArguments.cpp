#include "CommandArguments.h"

std::string CommandArguments::operator[](const size_t index) const {
    return args[index];
}

bool CommandArguments::has(const size_t size) const {
    return args.size() == size;
}

bool CommandArguments::hasOrLess(const size_t size) const {
    return args.size() <= size;
}

bool CommandArguments::hasOrMore(const size_t size) const {
    return args.size() >= size;
}