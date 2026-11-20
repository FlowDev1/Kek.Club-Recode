#pragma once

class HashedString {
public:
    [[nodiscard]] static constexpr uint64_t computeHash(const std::string_view str) {
        if (str.empty())
            return 0;
        uint64_t hash = 0xCBF29CE484222325ull;
        for (const char s : str) {
            hash = s ^ (0x100000001B3ull * hash);
        }
        return hash;
    }

    // Constructors
    [[nodiscard]] constexpr HashedString(std::nullptr_t = nullptr) noexcept : strHash(0), lastMatch(nullptr) {}

    [[nodiscard]] constexpr HashedString(const uint64_t h, char const* str) noexcept : strHash(h), str(str), lastMatch(nullptr) {}

    [[nodiscard]] constexpr HashedString(const std::string_view str) noexcept : strHash(computeHash(str)), str(str), lastMatch(nullptr) {}

    [[nodiscard]] constexpr HashedString(std::string&& s) noexcept : strHash(computeHash(s)), str(std::move(s)), lastMatch(nullptr) {}
    [[nodiscard]] constexpr HashedString(char const* str) noexcept : HashedString(std::string{str}) {}

    [[nodiscard]] constexpr HashedString(HashedString const& other) noexcept : strHash(other.strHash), str(other.str), lastMatch(nullptr) {}

    [[nodiscard]] constexpr HashedString(HashedString&& other) noexcept : strHash(other.strHash), str(std::move(other.str)), lastMatch(other.lastMatch) {
        other.strHash = 0;
        other.lastMatch = nullptr;
    }

    [[nodiscard]] constexpr HashedString& operator=(HashedString const& other) noexcept {
        if (this == &other) {
            return *this;
        }
        strHash = other.strHash;
        str = other.str;
        lastMatch = nullptr;
        return *this;
    }

    [[nodiscard]] constexpr HashedString& operator=(HashedString&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        strHash = other.strHash;
        str = std::move(other.str);
        lastMatch = other.lastMatch;
        other.strHash = 0;
        other.lastMatch = nullptr;
        return *this;
    }

    // Accessors
    [[nodiscard]] constexpr char const* c_str() const noexcept { return str.c_str(); }

    [[nodiscard]] constexpr std::string const& getString() const noexcept { return str; }

    [[nodiscard]] constexpr uint64_t getHash() const noexcept { return strHash; }

    [[nodiscard]] constexpr bool empty() const noexcept { return str.empty(); }

    // Mutators
    constexpr void clear() noexcept {
        strHash = 0;
        str.clear();
        lastMatch = nullptr;
    }

    // Operators
    template <typename StringType>
    [[nodiscard]] constexpr bool operator==(StringType const& rhs) const noexcept {
        return str == rhs;
    }

    [[nodiscard]] constexpr bool operator==(HashedString const& other) const noexcept {
        if (strHash == other.strHash) {
            if (lastMatch == std::addressof(other) && other.lastMatch == this) {
                return true;
            }
            if (str == other.str) {
                lastMatch = std::addressof(other);
                other.lastMatch = this;
                return true;
            }
        }
        lastMatch = nullptr;
        return false;
    }

    template <typename StringType>
    [[nodiscard]] constexpr bool operator!=(StringType const& rhs) const noexcept {
        return str != rhs;
    }

    [[nodiscard]] constexpr bool operator!=(HashedString const& other) const noexcept { return !(*this == other); }

    [[nodiscard]] constexpr std::strong_ordering operator<=>(HashedString const& other) const noexcept {
        if (strHash != other.strHash) {
            return strHash <=> other.strHash;
        }
        return str <=> other.str;
    }

    // Convertors
    [[nodiscard]] constexpr operator std::string const&() const { return str; }

    [[nodiscard]] constexpr operator std::string_view() const { return std::string_view(str); }

    uint64_t strHash;
    std::string str;
    mutable HashedString const* lastMatch;
};

namespace std {
    template <>
    struct hash<HashedString> {
        size_t operator()(HashedString const& str) const noexcept { return str.getHash(); }
    };
}