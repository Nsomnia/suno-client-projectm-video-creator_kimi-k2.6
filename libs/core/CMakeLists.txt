add_library(aether_core)

target_sources(aether_core PRIVATE
    src/dummy.cpp
)

target_include_directories(aether_core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(aether::core ALIAS aether_core)
