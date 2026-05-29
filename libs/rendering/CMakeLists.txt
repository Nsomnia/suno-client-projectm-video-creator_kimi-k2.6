add_library(aether_rendering)

target_sources(aether_rendering PRIVATE
    src/PlaceholderRenderer.cpp
    src/RenderEngine.cpp
    src/VisualizerItem.cpp
    include/aether/rendering/IRenderer.h
    include/aether/rendering/PlaceholderRenderer.h
    include/aether/rendering/RenderEngine.h
    include/aether/rendering/VisualizerItem.h
)

target_include_directories(aether_rendering PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(aether_rendering PUBLIC
    Qt6::Core
    Qt6::Quick
    Qt6::Gui
    aether::core
)

add_library(aether::rendering ALIAS aether_rendering)
