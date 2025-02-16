/**
 * @file main.cpp
 * @author Yumengmeng
 * @brief build the pharser tree, check it and carry out once
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "steps.h"
#include "state.h"
#include "pharser.h"
using namespace std;

int main()
{
    Pharser pharser;                               // 创建语法分析分析树对象
    bool buildsucceed = pharser.build();           // 构建分析树
    if (buildsucceed && pharser.check_issucceed()) // 如果分析树构建成功，则继续
    {
        cout << "read the script file succeed!" << endl;
        if (pharser.checkit()) // 检查分析树
        {
            cout << "check the script file succeed!" << endl;
            pharser.carryout(); // 执行程序
        }
    }

    return 0;
}