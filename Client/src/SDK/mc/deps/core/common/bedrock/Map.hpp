#pragma once

#include <vector>
#include <algorithm>

namespace Bedrock {
    template <typename Key, typename Value>
    class Map {
        std::vector<Key> keys;
        std::vector<Value> values;
        void* unk{};

    public:
        Key* getKeyFromValue(const Value& value) {
            if (this->keys.size() != this->values.size())
                return nullptr;

            for (std::size_t i = 0; i < this->values.size(); i++) {
                if (this->values[i] == value)
                    return &this->keys[i];
            }

            return nullptr;
        }

        Value* getValue(const Key& key) {
            if (this->keys.size() != this->values.size())
                return nullptr;

            for (std::size_t i = 0; i < this->keys.size(); i++) {
                if (this->keys[i] == key)
                    return &this->values[i];
            }

            return nullptr;
        }

        bool containsKey(const Key& key) {
            return std::ranges::find(this->keys, key) != this->keys.end();
        }

        bool containsValue(const Value& value) {
            return std::ranges::find(this->values, value) != this->values.end();
        }

        std::vector<Key>& getKeys() {
            return this->keys;
        }

        std::vector<Value>& getValues() {
            return this->values;
        }
    };
}
