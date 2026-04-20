cmake_minimum_required(VERSION 3.20)

project(LeetCode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(main ${SRC_FILES})