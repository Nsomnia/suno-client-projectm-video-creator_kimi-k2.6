add_library(aether_network)

target_sources(aether_network PRIVATE
    src/dummy.cpp
)

target_include_directories(aether_network PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(aether::network ALIAS aether_network)
