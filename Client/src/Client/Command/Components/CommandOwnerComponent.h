#pragma once

#include "Command.h"

struct CommandOwnerComponent {
    std::unique_ptr<Command> command;
};