#include <gtest/gtest.h>
#include "SemanticStruct.hpp"

TEST(SemanticStructTest, 四元组toString测试)
{
    Quaternion q(Quaternion::Operation::ADD, "x", "y", "z"); // x = y + z
    std::string expected = "(+, x, y, z)";
    ASSERT_EQ(q.toString(), expected);
}