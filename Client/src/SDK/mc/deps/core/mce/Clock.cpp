#include "Clock.hpp"

float mce::Clock::getLastDeltaTime() {
    return hat::member_at<float>(this, 0x4);
}