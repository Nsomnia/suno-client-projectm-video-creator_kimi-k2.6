add_library(aether_audio)

target_sources(aether_audio PRIVATE
    src/dummy.cpp
)

target_include_directories(aether_audio PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(aether::audio ALIAS aether_audio)
