/**
 * @file jumptest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief test Step Jump
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "gtest/gtest.h"
#include "steps.h"

TEST(CheckTest, test)
{
    Jump noconditionjump("Teststate");
    Jump conditionjump("yes", "Teststate");
    EXPECT_EQ("Teststate", noconditionjump.check_nextstate());
    EXPECT_EQ("", noconditionjump.check_condition());
    EXPECT_EQ("Teststate", conditionjump.check_nextstate());
    EXPECT_EQ("yes", conditionjump.check_condition());
}