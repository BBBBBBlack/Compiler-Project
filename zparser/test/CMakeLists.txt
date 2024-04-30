# 设置测试文件
set(TEST_INCLUDE_FILES  ${SOURCE_DIR}/ParseTab.cpp ${SOURCE_DIR}/Parser.cpp ${SOURCE_DIR}/CST.cpp
        )

set(TEST_SOURCE_FILES ${TEST_INCLUDE_FILES} MyTest.cpp)
# set(ZLEX_TEST_SOURCE_FILES ${TEST_INCLUDE_FILES} ZLexTest.cpp)

# 添加测试执行文件
add_executable(MyTest ${TEST_SOURCE_FILES})
# add_executable(ZLexTest ${ZLEX_TEST_SOURCE_FILES})

# target_compile_options(MyTest PRIVATE -fno-access-control -O2)
target_compile_options(MyTest PRIVATE -fno-access-control -g -O0)
# target_compile_options(ZLexTest PRIVATE -fno-access-control)

# 找到 Google Test 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS})

# 链接 Google Test 框架
target_link_libraries(MyTest
        ${GTEST_BOTH_LIBRARIES}
        pthread)
# target_link_libraries(ZLexTest
#         ${GTEST_BOTH_LIBRARIES}
#         pthread)     

# 添加测试
gtest_discover_tests(MyTest)
# gtest_discover_tests(ZLexTest)