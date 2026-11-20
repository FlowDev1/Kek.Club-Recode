#pragma once

constexpr auto PI = 3.1415927f;
static constexpr float RAD_DEG = PI / 180.f;

namespace Math {
    constexpr size_t fnv1a_64_hash(const std::string_view str, const size_t hash = 14695981039346656037ULL) {
        return str.empty() ? hash : fnv1a_64_hash(str.substr(1), (hash ^ str[0]) * 1099511628211ULL);
    }

    consteval size_t compile_time_hash(const std::string_view str) {
        return fnv1a_64_hash(str);
    }

    inline size_t hash_runtime(const std::string_view str, const size_t hash = 14695981039346656037ULL) {
        return str.empty() ? hash : hash_runtime(str.substr(1), (hash ^ str[0]) * 1099511628211ULL);
    }
}