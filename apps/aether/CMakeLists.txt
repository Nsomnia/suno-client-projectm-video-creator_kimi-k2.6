find_package(Qt6 REQUIRED COMPONENTS Quick Quick3D ShaderTools)

qt_add_executable(aether)

target_sources(aether PRIVATE
    src/main.cpp
    qml/qml.qrc
)

target_link_libraries(aether PRIVATE
    aether::core
    aether::rendering
    aether::audio
    aether::network
    aether::ui
    Qt6::Quick
    Qt6::Quick3D
)

set_target_properties(aether PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
