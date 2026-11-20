#pragma once

#include "../../../client/renderer/matrix/MatrixStack.h"

namespace mce {
    class Camera {
    public:
        MatrixStack viewMatrixStack;
        MatrixStack worldMatrixStack;
        MatrixStack projectionMatrixStack;
        Matrix viewMatrix;
        Matrix projectionMatrix;
    };
}