cmake_minimum_required(VERSION 3.10)
project(zparser VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置构建目录
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(PARSE_CPP "${CMAKE_SOURCE_DIR}/data/parse.cpp" CACHE STRING "parse.cpp 文件路径")

# 设置源文件目录
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
file(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cpp)
list(REMOVE_ITEM SOURCE_FILES "${SOURCE_DIR}/main.cpp" "${SOURCE_DIR}/ZTableGenerator.cpp")
# zTableGenerator源文件
file(GLOB ZTABLE_GENERATOR_SOURCE_FILES ${SOURCE_FILES} "${SOURCE_DIR}/ZTableGenerator.cpp")

# 添加 include 目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加测试目录
add_subdirectory(test)
# 启用测试
enable_testing()

# 创建静态库
add_library(zparser_lib STATIC ${SOURCE_FILES})
target_compile_options(zparser_lib PRIVATE -O2)
target_link_options(zparser_lib PRIVATE -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)

# ZTableGenerator可执行文件
add_executable(ZTableGenerator ${ZTABLE_GENERATOR_SOURCE_FILES})
# target_compile_options(ZTableGenerator PRIVATE -O2)
target_compile_options(ZTableGenerator PRIVATE -O0 -g)
target_link_options(ZTableGenerator PRIVATE -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)

# 可以在build目录下使用 
# g++ -I ../include -o ZParser ../test/test1/parse.cpp libzparser_lib.a
# 进行编译
# add_executable(ZParser ${SOURCE_FILES})
# # 检查PARSE_CPP是否存在
# if(EXISTS ${PARSE_CPP})
#     # 如果PARSE_CPP存在，声明ZParser这个目标并向它添加源文件
#     message("PARSE_CPP: ${PARSE_CPP}")
#     target_sources(ZParser PRIVATE ${PARSE_CPP})
#     target_compile_options(ZParser PRIVATE -O0 -g)
#     # target_compile_options(ZParser PRIVATE -O2)
#     target_link_options(ZParser PRIVATE -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
# else()
#     message("File not found: ${PARSE_CPP} 文件不存在\nZParser未成功构建\n")
# endif()

