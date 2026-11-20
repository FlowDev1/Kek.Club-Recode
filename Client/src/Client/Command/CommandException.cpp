#include "CommandException.hpp"

CommandException::CommandException(const ArgumentParser::ParseError error) {
    switch (error) {
        case ArgumentParser::ParseError::InvalidArgument:
            msg = "Invalid argument";
            break;
        case ArgumentParser::ParseError::ResultOutOfRange:
            msg = "Result out of range";
            break;
        case ArgumentParser::ParseError::Other:
            msg = "Other error occured";
            break;
        default:
            msg = "Unknown error";
            break;
    }
}

const char* CommandException::what() const {
    return msg.c_str();
}