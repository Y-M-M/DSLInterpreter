/**
 * @file pharsertest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief test function and normal error of pharaser.cpp
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "gtest/gtest.h"
#include "pharser.h"

TEST(Judgetest, isalpha)
{
    istringstream input("../scripts/deposit.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    EXPECT_EQ(true, pharser.is_alpha('a'));
    EXPECT_EQ(true, pharser.is_alpha('A'));
    EXPECT_EQ(true, pharser.is_alpha('z'));
    EXPECT_EQ(true, pharser.is_alpha('Z'));
    EXPECT_EQ(false, pharser.is_alpha('$'));
    EXPECT_EQ(false, pharser.is_alpha('#'));
}

TEST(Judgetest, isnum)
{
    istringstream input("../scripts/deposit.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    EXPECT_EQ(true, pharser.is_num('0'));
    EXPECT_EQ(true, pharser.is_num('9'));
    EXPECT_EQ(false, pharser.is_num('a'));
}

TEST(Normal, succeed) // 测试build()和check_issucceed()函数
{
    istringstream input("../scripts/deposit.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    EXPECT_EQ(true, pharser.build());
    EXPECT_EQ(true, pharser.check_issucceed());
}

// 测试read_let()函数
TEST(ErrorTest, leterror)
{
    istringstream input("../scripts/leterror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 4: le It is an abnormal string and cannot be recognized!\n", output);
}

TEST(ErrorTest, nameerrror)
{
    istringstream input("../scripts/nameerror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 3: The variable name is invalid! Please check if the variable name complies with the standard: starting with a letter or underscore, only including numbers, letters, and underscores.\n", output);
}

TEST(ErrorTest, letisnererrror)
{
    istringstream input("../scripts/letisnererror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 17: There are unrelated lines between username and attribute definitions\n", output);
}

TEST(ErrorTest, asignerrror)
{
    istringstream input("../scripts/asignerror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 4: The variable was not assigned correctly! Please ensure that all variables you set have an initial value of '='.\n", output);
}

TEST(ErrorTest, valueerrror)
{
    istringstream input("../scripts/valueerror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 4: The variable was not assigned correctly! Please ensure that all variables you set have an initial value, which is a string or integer number of the package.\n", output);
}

TEST(ErrorTest, stringenderror)
{
    istringstream input("../scripts/stringenderror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 4: The string did not end properly!\n", output);
}

TEST(ErrorTest, enderror1)
{
    istringstream input("../scripts/enderror1.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 4: An abnormal string appeared at the end!\n", output);
}

TEST(ErrorTest, enderror2)
{
    istringstream input("../scripts/enderror2.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 3: An abnormal string appeared at the end!\n", output);
}

TEST(ErrorTest, stateerror)
{
    istringstream input("../scripts/stateerror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 10: Stae It is an abnormal string and cannot be recognized!\n", output);
}

TEST(ErrorTest, statenameerror)
{
    istringstream input("../scripts/statenameerror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 10: The status name is invalid! Please ensure that the name of State consists only of uppercase and lowercase letters.\n", output);
}

TEST(ErrorTest, steperror)
{
    istringstream input("../scripts/steperror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 11: tput It is an unrecognized step!\n", output);
}

TEST(ErrorTest, outputerror)
{
    istringstream input("../scripts/outputerror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 11: The output string is not wrapped by \"\n", output);
}

TEST(CheckTest, nostarterror)
{
    istringstream input("../scripts/nostart.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    pharser.build();
    testing::internal::CaptureStdout();
    bool result = pharser.checkit();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 69: State Start is not found!\n", output);
}

TEST(CheckTest, exiterror)
{
    istringstream input("../scripts/exiterror.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 79: Exitfortime The status is illegal! It may not be possible to leave this state, causing an error in the program.\n", output);
}

TEST(CheckTest, needtimeout)
{
    istringstream input("../scripts/needtimeout.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 44: The current status is illegal! In some cases, it may not be possible to leave this state correctly, please check carefully.\n", output);
}

TEST(CheckTest, needdefault) // 有条件跳转却没有default
{
    istringstream input("../scripts/needdefault.txt");
    cin.rdbuf(input.rdbuf());
    Pharser pharser;
    testing::internal::CaptureStdout();
    bool result = pharser.build();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(false, result);
    EXPECT_EQ("Compilation error!\nline 44: The current status is illegal! In some cases, it may not be possible to leave this state correctly, please check carefully.\n", output);
}