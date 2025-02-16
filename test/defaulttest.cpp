/**
 * @file defaulttest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief test of Step Default
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
    Default adefault("test output", "Teststate");
    EXPECT_EQ("test output", adefault.checkoutput());
    EXPECT_EQ("Teststate", adefault.checknextstate());
}
