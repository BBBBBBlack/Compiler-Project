cmake_minimum_required(VERSION 3.10)
project(zlex)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置构建目录
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# 设置源文件目录
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
file(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cpp)

# 添加 include 目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加测试目录
add_subdirectory(test)

add_executable(zlex ${SOURCE_FILES})
# target_link_libraries(zlex stdc++fs)

# 启用测试
enable_testing()