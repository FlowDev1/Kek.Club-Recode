#pragma once

class ClientInstanceScreenModel {
public:
    enum ChatMessageRestrictions : uint8_t {
        Allowed = 0,
        BlockedByPlatform = 1,
        BlockedByXBL = 2,
        Muted = 3,
        CommandDisabled = 4,
        ChatBlockedByNetease = 5
    };
};