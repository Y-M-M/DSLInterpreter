#ifndef STEPS_H
#define STEPS_H

#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;
class Output // Output输出给用户的提示信息
{
public:
    Output(const string &printout); // 构造函数
    Output(const Output &output);
    void carryout(); // 执行这条指令
    ~Output();
    ostream &printit(ostream &out) const;
    string checkoutput() const; // 返回私有成员变量printout

private:
    string printout; // 需要输出的字符串
};

class Exit // Exit用户退出
{
public:
    Exit(); // 构造函数
    Exit(const Exit &needexit);
    ~Exit();
    ostream &printit(ostream &out) const;

private:
};

class Waitinput // Waitinput读取用户输入
{
public:
    Waitinput(); // Waitinput的构造函数
    Waitinput(const Waitinput &waitinput);
    ~Waitinput();
    ostream &printit(ostream &out) const;
    bool limitiputtime(const int &timeout); // 接受用户输入并做超时处理
    string checkinput() const;

private:
    string input;       // 用户输入，统一当作字符串来处理
    bool inputreceived; // 是否在限定时间内接受到用户输入
    condition_variable cv;
};

class Jump // Jump 无条件跳转
{
public:
    Jump(const string &nextstate);                          // Jump的构造函数 无条件跳转
    Jump(const string &condition, const string &nextstate); // 有条件跳转
    ~Jump();
    ostream &printit(ostream &out) const;
    string check_nextstate() const; // 返回私有成员变量nextstate
    string check_condition() const; // 返回私有成员变量condition

private:
    string nextstate; // 下一个状态的状态名
    string condition; // 跳转条件
};

class Default
{
public:
    Default(const string &output, const string &nextstate);
    Default(const Default &nosuit);
    void carryout();
    ~Default();
    ostream &printit(ostream &out) const;
    string checknextstate() const; // 返回私有成员变量nextstate
    string checkoutput() const;    // 检查私有成员变量output

private:
    string output;    // 输出的提示信息
    string nextstate; // 下一个状态的状态名
};

class Timeout
{
public:
    Timeout(const int &time, const string &nextstate);
    Timeout(const Timeout &timeout);
    ~Timeout();
    ostream &printit(ostream &out) const;
    string check_nextstate() const; // 返回私有成员变量nextstate
    int check_time() const;         // 返回输入等待时间限制

private:
    int time;         // 等待时间限制
    string nextstate; // 下一个状态的状态名
};

class Compute
{
public:
    Compute(const string &variable, const int &oper);
    Compute(const Compute &compute);
    ~Compute();
    ostream &printit(ostream &out) const;
    string check_variable() const; // 返回私有成员变量variable
    int check_oper() const;        // 返回私有成员变量oper

private:
    string variable; // 变量名
    int oper;        // 运算符
};

class Compare
{
public:
    Compare(const string &variable, const int &oper, const string &nextstate);
    Compare(const Compare &compare);
    ~Compare();
    ostream &printit(ostream &out) const;
    string check_nextstate() const; // 返回私有成员变量nextstate
    string check_variable() const;  // 返回私有成员变量variable
    int check_oper() const;         // 返回私有成员变量oper

private:
    string varibale;  // 需要进行比较的变量名
    int oper;         // 比较运算的运算符
    string nextstate; // 下一个状态的状态名
};

#endif