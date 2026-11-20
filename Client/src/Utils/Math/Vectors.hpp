#pragma once

template <typename T>
struct Vec2Base {
    T x{};
    T y{};

    Vec2Base() = default;
    Vec2Base(T x, T y) : x(x), y(y) {}

    bool operator==(const Vec2Base& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vec2Base& other) const {
        return !(*this == other);
    }

    Vec2Base operator+(const Vec2Base& other) const {
        return Vec2Base(x + other.x, y + other.y);
    }

    Vec2Base operator-(const Vec2Base& other) const {
        return Vec2Base(x - other.x, y - other.y);
    }

    Vec2Base operator*(const Vec2Base& other) const {
        return Vec2Base(x * other.x, y * other.y);
    }

    Vec2Base operator*(T scalar) const {
        return Vec2Base(x * scalar, y * scalar);
    }

    Vec2Base operator/(T scalar) const {
        return Vec2Base(x / scalar, y / scalar);
    }
};

template <typename T>
struct Vec3Base {
    T x{};
    T y{};
    T z{};

    Vec3Base() = default;
    Vec3Base(T x, T y, T z) : x(x), y(y), z(z) {}

    [[nodiscard]] float len() const {
        return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    [[nodiscard]] Vec3Base cross(const Vec3Base& vec) const {
        return {this->y * vec.z + this->z * vec.y, this->z * vec.x + this->x * vec.z, this->x * vec.y + this->y * vec.x};
    }

    [[nodiscard]] Vec3Base normalize() const {
        const float length = len();

        if (length == 0.f)
            return {};

        return {this->x / length, this->y / length, this->z / length};
    }

    bool operator==(const Vec3Base& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vec3Base& other) const {
        return !(*this == other);
    }

    Vec3Base operator+(const Vec3Base& other) const {
        return Vec3Base(x + other.x, y + other.y, z + other.z);
    }

    Vec3Base operator-(const Vec3Base& other) const {
        return Vec3Base(x - other.x, y - other.y, z - other.z);
    }

    Vec3Base operator*(const Vec3Base& other) const {
        return Vec3Base(x * other.x, y * other.y, z * other.z);
    }

    Vec3Base operator*(T scalar) const {
        return Vec3Base(x * scalar, y * scalar, z * scalar);
    }

    Vec3Base operator/(T scalar) const {
        return Vec3Base(x / scalar, y / scalar, z / scalar);
    }
};

template <typename T>
struct Vec4Base {
    T x{};
    T y{};
    T z{};
    T w{};

    Vec4Base() = default;
    Vec4Base(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    bool operator==(const Vec4Base& other) const {
        return x == other.x && y == other.y && z == other.z && w == other.w;
    }

    bool operator!=(const Vec4Base& other) const {
        return !(*this == other);
    }

    Vec4Base operator+(const Vec4Base& other) const {
        return Vec4Base(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    Vec4Base operator-(const Vec4Base& other) const {
        return Vec4Base(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    Vec4Base operator*(const Vec4Base& other) const {
        return Vec4Base(x * other.x, y * other.y, z * other.z, w * other.w);
    }

    Vec4Base operator*(T scalar) const {
        return Vec4Base(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    Vec4Base operator/(T scalar) const {
        return Vec4Base(x / scalar, y / scalar, z / scalar, w / scalar);
    }
};

using Vec2 = Vec2Base<float>;
using Vec3 = Vec3Base<float>;
using BlockPos = Vec3Base<int32_t>;
using RectangleArea = Vec4Base<float>;

struct QuadVertexHolder { // top left, top right, bottom left, bottom right
    Vec2 pos1, pos2, pos3, pos4;
    Vec2 uv1, uv2, uv3, uv4;
};