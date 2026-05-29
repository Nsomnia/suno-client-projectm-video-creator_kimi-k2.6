add_library(aether_ui)

target_sources(aether_ui PRIVATE
    src/dummy.cpp
)

target_include_directories(aether_ui PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_library(aether::ui ALIAS aether_ui)
