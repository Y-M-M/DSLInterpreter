#ifndef STATE_H
#define STATE_H

#include "steps.h"
#include <vector>

using namespace std;
class State // 需要定义拷贝构造函数
{
public:
    State();                                                      // State 的构造函数
    State(const State &state);                                    // State的拷贝构造函数
    ~State();                                                     // State的析构函数
    void clear_it();                                              // 删除当前state里存储的内容
    void putit_valid();                                           // 将is_vlaid置为1，表示程序可以退出
    bool check_valid() const;                                     // 检查is_valid是否为1
    void putit_need();                                            // 添加等待Timeout的需要need_input
    void addcon_need();                                           // 添加等待条件跳转的需要
    void reducecon_need();                                        // 减少等待条件跳转的需要
    bool check_need();                                            // 检查等待Timeout的需要
    void reduceinput_need();                                      // 减少等待Timeout的需要
    void addstep(string stepname, int stepid);                    // 插入step
    void adddefault_need();                                       // 添加等待default的需要need_default
    void reducedefault_need();                                    // 减少等待default的需要
    bool check_conjumpneed();                                     // 查看是否需要有条件跳转
    bool check_defaultneed();                                     // 检查是否需要default
    friend ostream &operator<<(ostream &out, const State &state); // 运算符重载，打印信息
    vector<pair<string, int>> checksteps() const;                 // 返回私有成员steps

private:
    vector<pair<string, int>> steps; // 存储当前state需要进行的所有操作
    bool is_valid;                   // 存储当前状态能否正常退出
    bool need_input;                 // 记录是否需要等待timeout
    bool need_default;               // 记录是否需要default
    bool need_conjump;               // 记录是否可以有条件跳转
};

#endif // STATE_H
