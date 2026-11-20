#pragma once

#include "ResourceFileSystem.hpp"

class ResourceLocation {
public:
    ResourceFileSystem fileSystem;
    std::string path;
    uint64_t pathHash{};
    uint64_t fullHash{};

    ResourceLocation() : fileSystem(ResourceFileSystem::Invalid) {}

    ResourceLocation(const std::string& filePath, const bool external) {
        this->path = filePath;
        if (external)
            this->fileSystem = ResourceFileSystem::Raw;
    }

    ResourceLocation(const std::string_view filePath, const bool external) {
        this->path = filePath;
        if (external)
            this->fileSystem = ResourceFileSystem::Raw;
    }
};