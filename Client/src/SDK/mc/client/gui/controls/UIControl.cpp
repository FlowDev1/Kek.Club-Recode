#include "UIControl.h"

std::string UIControl::getName() {
    return hat::member_at<std::string>(this, 0x20);
}