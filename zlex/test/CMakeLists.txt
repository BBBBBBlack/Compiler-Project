# 设置测试文件
set(TEST_SOURCE_FILES FATest.cpp ${SOURCE_DIR}/FA.cpp ${SOURCE_DIR}/Symbol.cpp)

# 添加测试执行文件
add_executable(FATest ${TEST_SOURCE_FILES})

# 找到 Google Test 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS})

# 链接 Google Test 框架
target_link_libraries(FATest
        ${GTEST_BOTH_LIBRARIES}
        pthread )

# 添加测试
gtest_discover_tests(FATest)