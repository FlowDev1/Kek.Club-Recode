#pragma once

#include "TextureWrapping.hpp"

namespace mce {
    struct TextureWrappingDescription {
        TextureWrapping uAddress;
        TextureWrapping vAddress;
        TextureWrapping wAddress;
    };
}
