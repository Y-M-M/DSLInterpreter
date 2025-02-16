/**
 * @file recordtest.cpp
 * @author Yumengmeng (you@domain.com)
 * @brief test for function of class Record
 * @version 0.1
 * @date 2024-11-29
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "gtest/gtest.h"
#include "record.h"

TEST(ModifyTest, addstringtest) // 测试add_string()和find_string()函数
{
    Record record;
    record.add_string("string1", "ok");
    record.add_string("string2", "yes");
    EXPECT_EQ("ok", record.find_string("string1"));
    EXPECT_EQ("yes", record.find_string("string2"));
}

TEST(ModigyTest, addnumtest) // 测试add_num()和find_num()函数
{
    Record record;
    record.add_num("num1", 3);
    record.add_num("num2", 4);
    EXPECT_EQ(3, record.find_num("num1"));
    EXPECT_EQ(4, record.find_num("num2"));
}

TEST(ModifyTest, cleartest) // 测试celar_it函数
{
    Record record;
    record.add_num("num", 2);
    record.add_string("string1", "yes");
    record.clear_it();
    EXPECT_EQ(0, record.find_num("num"));
    EXPECT_EQ("", record.find_string("string1"));
}

TEST(OperTest, addtest) // 测试addit()函数
{
    Record record;
    record.add_num("testnumadd", 5);
    record.addit("testnumadd", 3); // 正常的加法操作
    EXPECT_EQ(8, record.find_num("testnumadd"));
    record.addit("testnumadd1", 4); // 对未定义变量进行加操作
    EXPECT_EQ(4, record.find_num("testnumadd1"));
}

TEST(OperTest, reducetest) // 测试reduceit()函数
{
    Record record;
    record.add_num("testnumreduce", 5);
    record.reductit("testnumreduce", 3);
    EXPECT_EQ(2, record.find_num("testnumreduce"));
    record.reductit("testnumreduce1", 1);
    EXPECT_EQ(-1, record.find_num("testnumreduce1"));
}