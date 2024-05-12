# 设置测试文件
file(GLOB TEST_INCLUDE_FILES "${SOURCE_DIR}/*.cpp")
list(REMOVE_ITEM TEST_INCLUDE_FILES "${SOURCE_DIR}/main.cpp")

set(MY_TEST_SOURCE_FILES ${TEST_INCLUDE_FILES} MyTest.cpp)
set(CONFIG_TEST_SOURCE_FILES ${TEST_INCLUDE_FILES} ConfigTest.cpp)
set(FA_TEST_SOURCE_FILES ${TEST_INCLUDE_FILES} FATest.cpp)

# 添加测试执行文件
add_executable(MyTest ${MY_TEST_SOURCE_FILES})
add_executable(ConfigTest ${CONFIG_TEST_SOURCE_FILES})
add_executable(FATest ${FA_TEST_SOURCE_FILES})

# target_compile_options(MyTest PRIVATE -fno-access-control -O2)
target_compile_options(MyTest PRIVATE -fno-access-control -g -O0 -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
target_compile_options(ConfigTest PRIVATE -fno-access-control -g -O0 -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
target_compile_options(FATest PRIVATE -fno-access-control -g -O0 -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)


# 找到 Google Test 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS})

# 链接 Google Test 框架
target_link_libraries(MyTest
        ${GTEST_BOTH_LIBRARIES}
        pthread)
target_link_libraries(ConfigTest
        ${GTEST_BOTH_LIBRARIES}
        pthread)     
target_link_libraries(FATest
        ${GTEST_BOTH_LIBRARIES}
        pthread)


# 添加测试
gtest_discover_tests(MyTest)
gtest_discover_tests(ConfigTest)
gtest_discover_tests(FATest)

# 可执行文件测试
set(PARSE_TEST_SOURCE_FILES ${TEST_INCLUDE_FILES} ParseTest.cpp)

add_executable(ParseTest ${PARSE_TEST_SOURCE_FILES})
target_compile_options(ParseTest PRIVATE -fno-access-control -g -O0 -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)

if(EXISTS "${CMAKE_SOURCE_DIR}/test/out/config/parse.cpp")
        add_executable(GenParseTest ${TEST_INCLUDE_FILES} "${CMAKE_SOURCE_DIR}/test/out/config/parse.cpp")
endif()