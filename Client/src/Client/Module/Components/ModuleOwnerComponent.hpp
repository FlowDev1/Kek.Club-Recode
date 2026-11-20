#pragma once

#include "../Module.hpp"

struct ModuleOwnerComponent {
    std::unique_ptr<Module> module;
};