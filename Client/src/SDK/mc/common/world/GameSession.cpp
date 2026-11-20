#include "GameSession.hpp"

std::unique_ptr<NetEventCallback>& GameSession::getClientNetworkHandler() {
    return hat::member_at<std::unique_ptr<NetEventCallback>>(this, 0x48);
}