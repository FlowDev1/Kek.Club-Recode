#include "ScreenView.h"

VisualTree* ScreenView::getVisualTree() {
    return hat::member_at<std::unique_ptr<VisualTree>>(this, 0x48).get();
}

std::string ScreenView::getCurrentScreenName() {
    return getVisualTree()->getRootControl()->getName();
}