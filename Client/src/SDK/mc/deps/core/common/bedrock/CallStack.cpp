#include "CallStack.hpp"

namespace Bedrock::Detail {
    CallStack::Context createContext(const std::string& value) {
        CallStack::Context context;

        context.value = value;

        return context;
    }
}
