add_library(aether_core)

CPMAddPackage("gh:nlohmann/json@3.11.3")
CPMAddPackage("gh:ToruNiina/toml11@3.7.1")
CPMAddPackage("gh:gabime/spdlog@1.13.0")

target_sources(aether_core PRIVATE
    src/ApplicationContext.cpp
    src/ServiceRegistry.cpp
    src/Logger.cpp
    src/ConfigManager.cpp
    src/EventBus.cpp
    src/VersionInfo.cpp
    include/aether/core/ApplicationContext.h
    include/aether/core/ServiceRegistry.h
    include/aether/core/IService.h
    include/aether/core/Logger.h
    include/aether/core/ConfigManager.h
    include/aether/core/EventBus.h
    include/aether/core/VersionInfo.h
)

target_include_directories(aether_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(aether_core PUBLIC
    Qt6::Core
    nlohmann_json::nlohmann_json
    toml11::toml11
    spdlog::spdlog
)

add_library(aether::core ALIAS aether_core)
