#include "Platform_UWP.h"

MinecraftGame* Bedrock::Platform_UWP::getMinecraftGame() {
    return hat::member_at<MinecraftGame*>(this, 0x38);
}

AppPlatform* Bedrock::Platform_UWP::getAppPlatform() {
    return hat::member_at<AppPlatform*>(this, 0x58);
}