/**
 * @file state.cpp
 * @author Yumengmeng
 * @brief class State identified by user
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "state.h"

State::State() // State的构造函数
{
    this->is_valid = 0;
    this->need_input = 0;
    this->need_default = 0;
    this->need_conjump = 0;
}

State::State(const State &state) // State的拷贝构造函数
{
    this->steps = state.steps;
    this->is_valid = state.is_valid;
    this->need_input = state.need_input;
    this->need_default = state.need_default;
    this->need_conjump = state.need_conjump;
}

State::~State() // State的析构函数
{
}

void State::clear_it() // 删除当前state里存储的内容
{
    this->steps.clear();
    this->is_valid = 0;
    this->need_input = 0;
    this->need_default = 0;
    this->need_conjump = 0;
}

void State::putit_valid() // 将is_vlaid置为1，表示程序可以退出
{
    this->is_valid = 1;
}

bool State::check_valid() const // 检查is_valid是否为1
{
    if (!this->is_valid)
        return false;
    if (this->need_input)
        return false;
    if (this->need_default)
        return false;
    if (this->need_conjump)
        return false;
    return true;
}

void State::putit_need() // 添加等待Timeout的需要need_input
{
    this->need_input = 1;
}

bool State::check_need() // 检查等待Timeout的需要
{
    return this->need_input;
}

void State::reduceinput_need() // 减少等待Timeout的需要
{
    this->need_input = false;
}

void State::addstep(string stepname, int stepid) // 插入step
{
    this->steps.push_back(make_pair(stepname, stepid));
}

void State::adddefault_need() // 添加等待default的需要need_default
{
    this->need_default = true;
}

void State::reducedefault_need() // 减少等待default的需要
{
    this->need_default = false;
}

void State::addcon_need() // 添加等待条件跳转的需要
{
    this->need_conjump = true;
}

void State::reducecon_need() // 减少等待条件跳转的需要
{
    this->need_conjump = false;
}

bool State::check_conjumpneed() // 查看是否需要有条件跳转
{
    return this->need_conjump;
}

ostream &operator<<(ostream &out, const State &state) // 运算符重载，打印信息
{
    // out << "print steps in times:" << endl;
    for (int i = 0; i < state.steps.size(); i++)
    {
        out << state.steps[i].first << ", " << state.steps[i].second << endl;
        // cout << i << endl;
        // cout << "state.steps.size() = " << state.steps.size() << endl;
        // cout << state.steps[i] << endl;
        // state.steps[i]->carryout();
        // state.steps[i]->printit(out);
    }
    return out;
}

vector<pair<string, int>> State::checksteps() const // 返回私有成员steps
{
    return this->steps;
}

bool State::check_defaultneed()
{
    return this->need_default;
}