#include "MainView.hpp"

Bedrock::Platform_UWP* MainView::getPlatformUWP() {
    return hat::member_at<Bedrock::Platform_UWP*>(this, 0x118);
}