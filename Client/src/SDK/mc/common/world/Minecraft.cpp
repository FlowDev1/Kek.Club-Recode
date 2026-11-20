#include "Minecraft.hpp"

#include "../../../../Utils/Memory.hpp"

std::unique_ptr<GameSession>& Minecraft::getGameSession() {
    return hat::member_at<std::unique_ptr<GameSession>>(this, 0xC8);
}

StackRefResult<EntityRegistry> Minecraft::getEntityRegistry() {
    return Memory::callVFunc<1, &Minecraft::getEntityRegistry>(this);
}