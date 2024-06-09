# 找到 Google Test 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS})

function(add_test_executable TEST_NAME)
    set(TEST_SOURCE_FILES ${TEST_NAME}.cpp)
    add_executable(${TEST_NAME} ${TEST_SOURCE_FILES})
    target_link_libraries(${TEST_NAME} zparser_lib)
    target_compile_options(${TEST_NAME} PRIVATE -fno-access-control -g -O0 -DCMAKE_CXX_COMPILER_LAUNCHER=ccache)
    target_link_libraries(${TEST_NAME} ${GTEST_BOTH_LIBRARIES} pthread)
    gtest_discover_tests(${TEST_NAME})
endfunction()

# 添加测试执行文件
add_test_executable(MyTest)
add_test_executable(ConfigTest)
add_test_executable(FATest)
add_test_executable(SemanticTest)

# 可执行文件测试
# add_test_executable(ParseTest)

# 一个测试文件
if(EXISTS "${CMAKE_SOURCE_DIR}/test/out/config/parse.cpp")
    add_executable(GenParseTest "${CMAKE_SOURCE_DIR}/test/out/config/parse.cpp")
    target_link_libraries(GenParseTest zparser_lib)
endif()

# test1
# if(EXISTS "${CMAKE_SOURCE_DIR}/test/test1/parse.cpp")
#     add_executable(ParseTest1 "${CMAKE_SOURCE_DIR}/test/out/config/parse.cpp")
#     target_link_libraries(ParseTest1 zparser_lib)
# endif()