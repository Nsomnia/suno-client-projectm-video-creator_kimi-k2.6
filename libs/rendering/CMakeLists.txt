add_library(aether_rendering)

target_sources(aether_rendering PRIVATE
    src/dummy.cpp
)

target_include_directories(aether_rendering PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(aether::rendering ALIAS aether_rendering)
