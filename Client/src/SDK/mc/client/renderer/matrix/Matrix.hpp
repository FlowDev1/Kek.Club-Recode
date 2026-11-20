#pragma once

struct Matrix {
    union {
        glm::mat4x4 matrix;
    };
};