#include "MathUtility.hpp"

#include "../../../../../Signatures/SigManager.hpp"

Vec2 mce::MathUtility::getRotationFromNegZToVector(const Vec3& vec) {
    static auto func = Memory::getFunction<&MathUtility::getRotationFromNegZToVector>(GET_SIGNATURE("mce::MathUtility::getRotationFromNegZToVector"));
    return func(vec);
}