#pragma once

#include "../controls/VisualTree.h"

class ScreenView {
public:
    VisualTree* getVisualTree();

    std::string getCurrentScreenName();
};