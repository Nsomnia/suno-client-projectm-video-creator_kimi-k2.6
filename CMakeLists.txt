cmake_minimum_required(VERSION 3.25)
project(aether VERSION 0.1.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick)

include(cmake/CPM.cmake)

add_subdirectory(libs/core)
add_subdirectory(libs/rendering)
add_subdirectory(libs/audio)
add_subdirectory(libs/network)
add_subdirectory(libs/ui)
add_subdirectory(apps/aether)
