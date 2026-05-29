find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_add_executable(aether)

set_source_files_properties(qml/qml.qrc PROPERTIES QT_RESOURCE_PREFIX "/")

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
)

set_target_properties(aether PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)
