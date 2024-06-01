cmake_minimum_required(VERSION 3.28)

project(compgraph)

include("C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
include_directories(./include)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)

find_package(GLUT REQUIRED)
add_executable(${PROJECT_NAME} src/main.cpp src/basic.cpp src/bresenham_line.cpp src/transforms_2d.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE GLUT::GLUT)
