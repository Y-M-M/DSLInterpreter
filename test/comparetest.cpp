/**
 * @file comparetest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief test of Step Compare
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "gtest/gtest.h"
#include "steps.h"

TEST(CheckTest, check)
{
    Compare compare("yes", 1, "Nextstate");
    EXPECT_EQ("yes", compare.check_variable());
    EXPECT_EQ(1, compare.check_oper());
    EXPECT_EQ("Nextstate", compare.check_nextstate());
}
