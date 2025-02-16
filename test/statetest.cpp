/**
 * @file statetest.cpp
 * @author Yumengmeng
 * @brief test for State
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "gtest/gtest.h"
#include "state.h"

TEST(FlagTest, isvalid)
{
    State state;
    EXPECT_EQ(false, state.check_valid());
    state.putit_valid();
    EXPECT_EQ(true, state.check_valid());
}

TEST(FlagTest, needinput)
{
    State state;
    EXPECT_EQ(false, state.check_need());
    state.putit_need();
    EXPECT_EQ(true, state.check_need());
    state.reduceinput_need();
    EXPECT_EQ(false, state.check_need());
}

TEST(FlagTest, needdefault)
{
    State state;
    EXPECT_EQ(false, state.check_defaultneed());
    state.adddefault_need();
    EXPECT_EQ(true, state.check_defaultneed());
    state.reducedefault_need();
    EXPECT_EQ(false, state.check_defaultneed());
}

TEST(FlagTest, needconjump)
{
    State state;
    EXPECT_EQ(false, state.check_conjumpneed());
    state.addcon_need();
    EXPECT_EQ(true, state.check_conjumpneed());
    state.reducecon_need();
    EXPECT_EQ(false, state.check_conjumpneed());
}

TEST(StepTest, step)
{
    State state;
    vector<pair<string, int>> steps;
    EXPECT_EQ(steps, state.checksteps());
    state.addstep("teststep", 0);
    EXPECT_EQ("teststep", state.checksteps()[0].first);
    EXPECT_EQ(0, state.checksteps()[0].second);
}