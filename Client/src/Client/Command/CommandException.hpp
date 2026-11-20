#pragma once

#include "ArgumentParser.hpp"

class CommandException : std::exception {
    std::string msg;

public:
    explicit CommandException(ArgumentParser::ParseError error);

    [[nodiscard]] const char* what() const override;
};