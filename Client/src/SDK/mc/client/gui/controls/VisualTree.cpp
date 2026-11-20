#include "VisualTree.hpp"

UIControl* VisualTree::getRootControl() {
    return hat::member_at<std::shared_ptr<UIControl>>(this, 0x8).get();
}