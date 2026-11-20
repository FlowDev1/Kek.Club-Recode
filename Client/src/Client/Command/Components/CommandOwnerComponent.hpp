#pragma once

#include "../Command.hpp"

struct CommandOwnerComponent {
    std::unique_ptr<Command> command;
};