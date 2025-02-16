/**
 * @file outputtest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief test Step Output
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
    Output output("test output");
    EXPECT_EQ("test output", output.checkoutput());
}