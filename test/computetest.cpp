#include "gtest/gtest.h"
#include "steps.h"

TEST(ChectTest, check)
{
    Compute compute("test", 1);
    EXPECT_EQ("test", compute.check_variable());
    EXPECT_EQ(1, compute.check_oper());
}
