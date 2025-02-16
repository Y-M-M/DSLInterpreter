#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Record
{
public:
    Record();                                                       // 构造函数
    Record(const Record &record);                                   // 拷贝构造函数
    void add_string(const string &id, const string &value);         // 在记录表里添加string记录
    void add_num(const string &id, const int &num);                 // 在记录表里添加number记录
    void clear_it();                                                // 清空记录表
    friend ostream &operator<<(ostream &out, const Record &record); // 运算符重载，输出Record
    int find_num(const string &numname);                            // 在number记录中查找有没有numname
    string find_string(const string &stringname);                   // 在string记录中查找有没有stringname
    void reductit(const string &variablename, const int &reducer);  // 对记录做减法
    void addit(const string &variablename, const int &adder);       // 对记录做加法

private:
    map<string, int> nums;          // number记录
    map<string, string> characters; // string记录
};

#endif