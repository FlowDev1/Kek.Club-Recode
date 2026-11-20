#pragma once

#include "../../../../../Utils/Math/Vectors.hpp"

namespace mce {
    class MathUtility {
    public:
        static Vec2 getRotationFromNegZToVector(const Vec3& vec);
    };
}