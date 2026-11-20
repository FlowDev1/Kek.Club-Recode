#pragma once

#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>

#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <initializer_list>
#include <thread>
#include <unordered_map>
#include <map>
#include <memory>
#include <urlmon.h>
#include <ranges>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <utility>
#include <cassert>
#include <string_view>
#include <algorithm>
#include <cctype>
#include <minwindef.h>
#include <chrono>
#include <future>
#include <variant>
#include <expected>
#include <stack>

#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Data.Xml.Dom.h>
#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.ApplicationModel.Core.h>

#include <magic_enum/magic_enum.hpp>
#include <magic_enum/magic_enum_utility.hpp>
#include <libhat/Access.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

#include <entt/entt.hpp>
#include <entt/entity/handle.hpp>
#include <entt/entity/registry.hpp>

#include "../Includes/json.h"
#include "../Includes/XorStr.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "src/Utils/Utils.h"
#include "src/Utils/Logger.h"
#include "src/SDK/mc/common/ColorFormat.h"
#include "src/Utils/Internationalization/Internationalization.h"

using namespace winrt::Windows;
using json = nlohmann::json;