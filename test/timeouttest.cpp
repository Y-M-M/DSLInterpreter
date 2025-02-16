/**
 * @file timeouttest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief test of Step timeout
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
    Timeout timeout(20, "Teststate");
    EXPECT_EQ(20, timeout.check_time());
    EXPECT_EQ("Teststate", timeout.check_nextstate());
}