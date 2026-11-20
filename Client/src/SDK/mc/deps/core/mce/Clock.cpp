#include "Clock.h"

float mce::Clock::getLastDeltaTime() {
    return hat::member_at<float>(this, 0x4);
}