/**
 * @file steps.cpp
 * @author Yumengmeng
 * @brief Steps that users could identify
 * @version 0.1
 * @date 2024-12-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "steps.h"

extern const int maxsize = 1024;

Output::Output(const string &printout) // Output的构造函数
{
    this->printout = printout;
}

Output::Output(const Output &output)
{
    this->printout = output.printout;
}

void Output::carryout() // 执行Output指令
{
    cout << this->printout;
    cout << endl;
}

Output::~Output()
{
}

string Output::checkoutput() const // 返回私有成员变量printout
{
    return this->printout;
}

ostream &Output::printit(ostream &out) const
{
    out << "Begin to print ouput:" << endl;
    out << "Step Output:" << endl;
    out << "    " << this->printout << endl;
    return out;
}

Exit::Exit() // Exit的构造函数
{
}

Exit::Exit(const Exit &need_exit)
{
}

Exit::~Exit()
{
}

ostream &Exit::printit(ostream &out) const
{
    out << "Step Exit" << endl;
    return out;
}

Waitinput::Waitinput() // Waitinput的构造函数
{
    this->inputreceived = false;
}

Waitinput::Waitinput(const Waitinput &waitinput)
{
    this->inputreceived = waitinput.inputreceived;
    this->input = waitinput.input;
}

Waitinput::~Waitinput()
{
}

ostream &Waitinput::printit(ostream &out) const
{
    out << "Step Waitinput" << endl;
    return out;
}

string Waitinput::checkinput() const
{
    return this->input;
}

bool Waitinput::limitiputtime(const int &timeout) // 接受用户输入并做超时处理
{
    // 将标准输入设置为非阻塞模式
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0); // 调用 fcntl 函数获取标准输入（STDIN_FILENO）的当前文件状态标志，并将其存储在 flags 变量中
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK); // 这行代码将标准输入的状态标志设置为非阻塞模式。通过按位或操作将 O_NONBLOCK 添加到现有标志中，使得输入操作不会阻塞程序的执行。

    string input;
    auto start = std::chrono::steady_clock::now(); // 这行代码记录当前时间，使用 steady_clock 以便后续比较输入超时

    while (true)
    {
        char buffer[maxsize]; 
        ssize_t bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1); // 使用 read 函数从标准输入读取数据
        if (bytes_read > 0) // 检查是否成功读取了数据
        {
            buffer[bytes_read] = '\0'; // 末尾加0，当作字符串处理
            input += buffer;
            if (input.back() == '\n')
            { // 检测到完整输入
                this->input.assign(buffer, bytes_read - 1); // 将buffer中的字符除了换行符之外都读入到字符串input中
                return true;
            }
        }

        auto now = chrono::steady_clock::now();
        if (chrono::duration_cast<std::chrono::seconds>(now - start).count() >= timeout)
        {

            return false;
        }

        this_thread::sleep_for(chrono::milliseconds(100)); // 减少 CPU 占用
    }
}

Jump::Jump(const string &nextstate)
{
    this->nextstate = nextstate;
}

Jump::Jump(const string &condition, const string &nextstate)
{
    this->condition = condition;
    this->nextstate = nextstate;
}

Jump::~Jump()
{
}

string Jump::check_condition() const // 返回私有成员变量condition
{
    return this->condition;
}

string Jump::check_nextstate() const // 返回私有成员变量nextstate
{
    return this->nextstate;
}

ostream &Jump::printit(ostream &out) const
{
    out << "Step Jump:" << endl;
    if (!this->condition.empty())
    {
        out << "    condition: " << this->condition << endl;
    }
    out << "    nextstate: " << this->nextstate << endl;
    return out;
}

Default::Default(const string &output, const string &nextstate)
{
    this->output = output;
    this->nextstate = nextstate;
}

Default::Default(const Default &nosuit)
{
    this->output = nosuit.output;
    this->nextstate = nosuit.nextstate;
}

void Default::carryout()
{
    cout << this->output << endl;
}

Default::~Default()
{
}

ostream &Default::printit(ostream &out) const
{
    out << "Step Default: " << endl;
    out << "    output: " << this->output << endl;
    out << "    nextstate: " << this->nextstate << endl;
    return out;
}

string Default::checknextstate() const // 返回私有成员变量nextstate
{
    return this->nextstate;
}

string Default::checkoutput() const // 检查私有成员变量output
{
    return this->output;
}

Timeout::Timeout(const int &time, const string &nextstate)
{
    this->time = time;
    this->nextstate = nextstate;
}

Timeout::Timeout(const Timeout &timeout)
{
    this->time = timeout.time;
    this->nextstate = timeout.nextstate;
}

Timeout::~Timeout()
{
}

ostream &Timeout::printit(ostream &out) const
{
    out << "Step Timeout: " << endl;
    out << "    time: " << this->time << endl;
    out << "    nextstate: " << this->nextstate << endl;
    return out;
}

string Timeout::check_nextstate() const // 返回私有成员变量nextstate
{
    return this->nextstate;
}

int Timeout::check_time() const // 返回输入等待时间限制
{
    return this->time;
}

Compute::Compute(const string &variable, const int &oper)
{
    this->variable = variable;
    this->oper = oper;
}

Compute::Compute(const Compute &compute)
{
    this->variable = compute.variable;
    this->oper = compute.oper;
}

Compute::~Compute()
{
}

ostream &Compute::printit(ostream &out) const
{
    out << "Step Compute: " << endl;
    out << "    variable: " << variable << endl;
    out << "    operator: " << this->oper << endl;
    return out;
}

string Compute::check_variable() const // 返回私有成员变量variable
{
    return this->variable;
}

int Compute::check_oper() const // 返回私有成员变量oper
{
    return this->oper;
}

Compare::Compare(const string &variable, const int &oper, const string &nextstate)
{
    this->varibale = variable;
    this->oper = oper;
    this->nextstate = nextstate;
}

Compare::Compare(const Compare &compare)
{
    this->varibale = compare.varibale;
    this->oper = compare.oper;
    this->nextstate = compare.nextstate;
}

Compare::~Compare()
{
}

ostream &Compare::printit(ostream &out) const
{
    out << "Step Compare: " << endl;
    out << "    variable: " << this->varibale << endl;
    out << "    oper: " << this->oper << endl;
    out << "    nextstate: " << this->nextstate << endl;
    return out;
}

string Compare::check_nextstate() const
{
    return this->nextstate;
}

string Compare::check_variable() const
{
    return this->varibale;
}

int Compare::check_oper() const
{
    return this->oper;
}