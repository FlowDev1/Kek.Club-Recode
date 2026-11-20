#pragma once

#include "Module.h"

struct ModuleOwnerComponent {
    std::unique_ptr<Module> module;
};