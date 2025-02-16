#ifndef PHARSER_H
#define PHARSER_H

#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <set>
#include <unistd.h>   // fork()
#include <fcntl.h>    // open(), O_CREAT, O_WRONLY
#include <sys/file.h> // flock
#include <sys/wait.h> // waitpid
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include "state.h"
#include "record.h"
using namespace std;

// 读取关键词后指针所在的位置
const int afterstate = 5;
const int afterlet = 3;
const int aftertable = 4;
const int afteroutput = 6;
const int afterexit = 4;
const int afterwaitinput = 9;
const int afterjump = 4;
const int afterdefault = 7;
const int aftertimeout = 7;
const int aftercompare = 7;
const int afternotfind = 7;
const int textlen = 5;

const int maxsize = 1024; // 缓冲区最大长度
enum                      // 错误码
{
    succeed,         // 分析树构建成功
    let_error,       // 行首以l开头的单词不是'let'
    name_error,      // 变量名不符合要求
    assign_error,    // 没能为变量正确识别'='复制符号
    value_error,     // value不是整数或字符串
    stringend_error, // 字符串没能正确以"结束
    end_error,       // 行尾出现特别的符号
    uservalue_error, // 读取用户名时，value不是字符串
    state_error,     // 行首以'S'开头的单词不是State
    statename_error, // 状态名不合法
    step_error,      // step的名字出现错误
    output_error,    // 输出内容不是字符串(没能识别到第一个引号)
    invalid_error,   // 状态不合法
    nottimeout,      // 对于waitinput没有相应的timeout
    condition_error, // Jump指令的跳转条件读取失败
    not_info,        // default没有定义输出字符串
    time_error,      // Timeout中读取时间出错
    variable_error,  // Compare中定义变量出错
    oper_error,      // Compare中定义运算符出错
    to_error,        // Compare之后没有正确写to
    letisner_error,  // username与属性的定义之间有无关行
    no_userinput,    // 没有用户输入，却有条件跳转
};

enum // 用户输入相对于存储变量的比较
{
    lesser,      // 小于输入变量
    bigger,      // 大于输入变量
    lessequal,   // 小于等于输入变量
    biggerequal, // 大于等于输入变量
    equalit,     // 等于输入变量
    notequal,    // 不等于输入变量
};

enum // 用户对变量的操作
{
    addit,      // 加法操作
    reduceit,   // 减法操作
    assignment, // 赋值操作
};
class Pharser
{
public:
    Pharser();                                                                     // Pharser构造函数，打开文件，为buffer申请内存
    ~Pharser();                                                                    // 析构函数，关闭文件，释放为buffer申请的内存
    bool build();                                                                  // 构建分析树
    bool check_issucceed() const;                                                  // 检查是否分析成功
    bool is_alpha(const char &c) const;                                            // 判断当前字符是不是字母
    bool is_num(const char &c) const;                                              // 判断当前字符是不是数字
    void debug(const string &output);                                              // 在出现错误时输出行数和提示信息，并将is_success修改为0
    int read_let();                                                                // 读取用户自定义变量，返回错误码
    int read_value(const int &begin, const string &mainId);                        // 读取赋给变量的值
    int read_string_value(const int &begin);                                       // 读取赋给username的值
    void add_records();                                                            // 添加记录并清空当前username和record
    int read_state();                                                              // 读入状态，返回错误码
    int add_states();                                                              // 添加读入的状态至分析树中
    int read_step();                                                               // 读入一个step，返回错误码
    void out_invalid();                                                            // 输出状态不合法的提示信息
    void alert_enderror();                                                         // 字符串没有正确以双引号结束
    friend ostream &operator<<(ostream &out, const Pharser &pharser);              // 运算符重载，用于输出
    bool checkit();                                                                // 检查分析树的合法性
    void carryout();                                                               // 执行翻译好的程序
    int printvariable(const int &i, const string &output, const string &username); // 从records中查找变量并打印
    void printoutput(const string &output, const string &username);                // 打印脚本文件中定义的output信息
    void info();                                                                   // 打印时间戳

private:
    ifstream script;               // script文件指针
    map<string, State> states;     // 脚本文件定义的状态
    map<string, Record> records;   // 脚本文件中输入的记录
    int line;                      // 记录当前行
    char *buffer;                  // 缓冲区，从文件中读取一行并存储到buffer中
    bool is_succeed;               // 记录分析是否成功
    string username;               // 记录当前读取的记录的用户名
    Record record;                 // 记录当前读取的记录的属性
    string statename;              // 记录当前读取的状态名
    State state;                   // 记录当前读取的状态
    ofstream log;                  // 输出debug信息到log.txt文件中
    vector<Exit> allexits;         // 存储Step exit
    vector<Waitinput> allwaitings; // 存储Step waiting
    vector<Jump> alljumps;         // 存储Step Jump
    vector<Default> alldefaults;   // 存储Step Default
    vector<Timeout> alltimeous;    // 存储Step Timeout
    vector<Compare> allcompares;   // 存储Step Compare
    vector<Compute> allcomputes;   // 存储 Step Compute
    vector<Output> alloutputs;     // 存储Step Output
    string userinput;              // carryout的时候存储用户输入
    string nextstate;              // 存储目前正在处理的nextstate
};

#endif // PJARSER_H