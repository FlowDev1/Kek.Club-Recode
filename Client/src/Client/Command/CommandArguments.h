#pragma once

#include "ArgumentParser.h"
#include "CommandException.h"

struct CommandArguments {
    std::vector<std::string> args;

    explicit CommandArguments(const std::vector<std::string>& args) : args(args) {}

    std::string operator[](size_t index) const;

    [[nodiscard]] bool has(size_t size) const;
    [[nodiscard]] bool hasOrLess(size_t size) const;
    [[nodiscard]] bool hasOrMore(size_t size) const;

    template <typename T>
    decltype(auto) get(const size_t index) {
        auto expected = ArgumentParser::parse<T>(args[index]);
        if (!expected)
            throw CommandException(expected.error());
        return expected.value();
    }
};