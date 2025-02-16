/**
 * @file record.cpp
 * @author Yumengmeng
 * @brief a record for a user, including add, find, reduce... function
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "record.h"

Record::Record() // 构造函数
{
}

Record::Record(const Record &record) // 拷贝构造函数
{
    this->nums = record.nums;
    this->characters = record.characters;
}

void Record::add_string(const string &id, const string &value) // 在记录表里添加string记录
{
    characters[id] = value;
}

void Record::add_num(const string &id, const int &num) // 在记录表里添加number记录
{
    nums[id] = num;
}

void Record::clear_it() // 清空记录表
{
    this->nums.clear();
    this->characters.clear();
}

ostream &operator<<(ostream &out, const Record &record) // 运算符重载，输出Record
{
    out << "nums:" << endl;
    for (const auto &num : record.nums)
    {
        out << num.first << ": " << num.second << endl;
    }
    out << "strings:" << endl;
    for (const auto &character : record.characters)
    {
        out << character.first << ": " << character.second << endl;
    }
    return out;
}

int Record::find_num(const string &numname) // 在number记录中查找有没有numname
{
    if (nums.find(numname) != nums.end())
    {
        return nums[numname];
    }
    this->add_num(numname, 0);
    return 0;
}

string Record::find_string(const string &stringname) // 在string记录中查找有没有stringname
{
    string character;
    if (characters.find(stringname) != characters.end())
    {
        character = characters[stringname];
    }
    return character;
}

void Record::reductit(const string &variablename, const int &reducer) // 对记录做减法
{
    if (nums.find(variablename) == nums.end())
    {
        nums[variablename] = 0;
    }
    nums[variablename] -= reducer;
}

void Record::addit(const string &variablename, const int &adder) // 对记录做加法
{
    if (nums.find(variablename) == nums.end())
    {
        nums[variablename] = 0;
    }
    nums[variablename] += adder;
}