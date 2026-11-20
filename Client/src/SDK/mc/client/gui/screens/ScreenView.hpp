#pragma once

#include "../controls/VisualTree.hpp"

class ScreenView {
public:
    VisualTree* getVisualTree();

    std::string getCurrentScreenName();
};