/**
 * @file pharser.cpp
 * @author Yumengmeng
 * @brief construct the pharser tree
 * @version 0.1
 * @date 2024-11-27
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "pharser.h"

/**
 * @brief Construct a new Pharser:: Pharser object
 * function: open script and log file, apply storage for buffer
 */
Pharser::Pharser() // Pharser构造函数，打开文件，为buffer申请内存(Pharser constructor, open file, apply memory for buffer)
{
    this->is_succeed = 1;
    this->line = 0;
    this->buffer = new char[maxsize];
    this->log.open("log.txt", ios::out); // 打开log.txt文件，将debug信息输出到末尾
    log << "-----------------------------------------" << endl;
    info();
    log << endl;
    while (!script.is_open()) // 打开script.txt文件
    {
        cout << "Please enter the script file path and name (must be a.txt file): " << endl;
        info();
        log << "Please enter the script file path and name (must be a.txt file): " << endl;
        string filename; // 读取脚本文件名
        cin >> filename;

        info();
        log << "ok! filename is " << filename << endl;
        int len = filename.length();
        // 判断脚本文件是否是.txt文件
        if (len < textlen || filename[len - 1] != 't' || filename[len - 2] != 'x' || filename[len - 3] != 't' || filename[len - 4] != '.')
        {
            cout << "Please ensure that the file ends in .txt format! " << endl;
            info();
            log << "Please ensure that the file ends in .txt format! " << endl;
            continue; // 继续循环，重新要求用户输入(Continue the loop and ask the user to input again)
        }
        this->script.open(filename, ios::in);
        if (!script.is_open())
        {
            cout << "Script file failed to open! Please check if the file path is correct." << endl;
            info();
            log << "Script file failed to open! Please check if the file path is correct." << endl;
        }
        info();
        log << "open file succeed!" << endl
            << endl;
    }
}

/**
 * @brief Destroy the Pharser:: Pharser object
 * function: close files, delete the storage of buffer
 */
Pharser::~Pharser() // 析构函数，关闭文件，删除buffer的内存
{
    if (script.is_open())
        this->script.close(); // 关闭脚本文件
    if (buffer != nullptr)    // 检查指针是否为nullptr
    {
        delete[] buffer;  // 删除内存
        buffer = nullptr; // 将指针置为nullptr
    } // 删除为buffer申请的内存
    if (log.is_open())
        this->log.close(); // 关闭日志文件
}

/**
 * @brief read the script file to build a pharser tree
 *
 */
bool Pharser::build() // 构建分析树
{
    info();
    log << "begin to build analyze true!" << endl;
    while (!script.eof())
    {
        log << endl;
        memset(buffer, 0, maxsize);      // 清空缓冲区
        script.getline(buffer, maxsize); // 读入一整行
        line++;                          // 记录行号，便于输出提示信息
        info();
        log << "line " << line << " have been read!" << endl;
        string output;
        int i = 0, j = 0;
        int error_num;
        switch (buffer[0])
        {
        case 'l':
            error_num = read_let();
            switch (error_num)
            {
            case succeed:
                info();
                log << "read let succeed!" << endl;
                break;
            case let_error:
                i = 0;
                while (i < maxsize && buffer[i] != ' ' && buffer[i] != '\n')
                {
                    i++;
                }
                output.assign(this->buffer, i);
                output.append(" It is an abnormal string and cannot be recognized!");
                info();
                debug(output);
                return false;
                break;
            case name_error:
                info();
                debug("The variable name is invalid! Please check if the variable name complies with the standard: starting with a letter or underscore, only including numbers, letters, and underscores.");
                return false;
                break;
            case assign_error:
                info();
                debug("The variable was not assigned correctly! Please ensure that all variables you set have an initial value of '='.");
                return false;
                break;
            case value_error:
                info();
                debug("The variable was not assigned correctly! Please ensure that all variables you set have an initial value, which is a string or integer number of the package.");
                return false;
                break;
            case stringend_error:
                alert_enderror();
                return false;
                break;
            case end_error:
                info();
                debug("An abnormal string appeared at the end!");
                return false;
                break;
            case uservalue_error:
                info();
                debug("The variable was not assigned correctly! Please ensure that the initial value assigned to username is the string of the package.");
                return false;
                break;
            case letisner_error:
                info();
                debug("There are unrelated lines between username and attribute definitions");
                return false;
                break;
            }
            break;
        case 'S':
            if (!this->username.empty()) // 用户名不为空
            {
                add_records();
            }
            error_num = read_state();
            i = 0;
            output.clear();
            switch (error_num)
            {
            case succeed:
                break;
            case state_error:
                i = 0;
                while (i < maxsize && buffer[i] != ' ' && buffer[i] != '\n')
                {
                    i++;
                }
                output.assign(this->buffer, i);
                output.append(" It is an abnormal string and cannot be recognized!");
                info();
                debug(output);
                return false;
                break;
            case statename_error:
                info();
                debug("The status name is invalid! Please ensure that the name of State consists only of uppercase and lowercase letters.");
                return false;
                break;
            case output_error:
                info();
                debug("The output string is not wrapped by 'package!' (not starting with '\')");
                return false;
                break;
            case invalid_error:
                info();
                debug("The current status is illegal! In some cases, it may not be possible to leave this state correctly, please check carefully.");
                return false;
                break;
            case end_error:
                info();
                debug("An abnormal string appeared at the end!");
                return false;
                break;
            case stringend_error:
                alert_enderror();
                return false;
                break;
            }
            break;
        case '#':
            break;
        case ' ':
            error_num = read_step();
            if (buffer[1] != ' ' || buffer[2] != ' ' || buffer[3] != ' ')
            {
                info();
                debug("Illegal symbols appear at the beginning! Please check if there are any additional empty spaces or other undefined characters.");
                return false;
            }
            switch (error_num)
            {
            case succeed:
                break;
            case step_error:
                i = aftertable;
                j = i;
                while (j < maxsize && buffer[j] != ' ' && buffer[j] != '\n')
                {
                    j++;
                }
                output.clear();
                output.assign(buffer + i, j - i);
                output.append(" It is an unrecognized step!");
                info();
                debug(output);
                return false;
                break;
            case output_error:
                info();
                debug("The output string is not wrapped by \"");
                return false;
                break;
            case stringend_error:
                alert_enderror();
                return false;
                break;
            case nottimeout:
                info();
                debug("Waitinput does not have a corresponding Timeout!");
                return false;
                break;
            case condition_error:
                info();
                debug("The jump condition of the Jump instruction is incorrect! (Incorrect ending with \")");
                return false;
                break;
            case statename_error:
                info();
                debug("The statename is invalid! Please ensure that the status names are composed of uppercase or lowercase letters.");
                return false;
                break;
            case end_error:
                info();
                debug("An abnormal string appeared at the end!");
                return false;
                break;
            case not_info:
                info();
                debug("Default does not provide any output prompt information! (No string starting with \")");
                return false;
                break;
            case time_error:
                info();
                debug("I couldn't read the time correctly! Please ensure that the time is an integer in seconds.");
                return false;
                break;
            case variable_error:
                info();
                debug("varibalename is error! it should start with alpha or _, and include alpha, _, or number.");
                return false;
                break;
            case oper_error:
                info();
                debug("Illegal operator used!");
                return false;
                break;
            case to_error:
                info();
                debug("don\'t have normal \"to\"");
                return false;
                break;
            case no_userinput:
                info();
                debug("No user input, but conditional jump.");
                return false;
                break;
            }
            break;
        case '\n':
            break;
        case 0:
            break;
        default:
            info();
            debug("Illegal symbols appear at the beginning! Please check if there are any additional empty spaces or other undefined characters.");
            return false;
            break;
        }
    }
    if (!this->statename.empty()) // 将读到的最后一个状态插入分析树中
    {
        int error_num = this->add_states();
        if (error_num == invalid_error)
        {
            this->out_invalid();
            return false;
        }
    }
    if (!this->username.empty()) // 将最后读到的记录插入分析树中
    {
        this->add_records();
    }
    log << *this;
    return true;
}

/**
 * @brief return the private variable is_succeed
 *
 * @return true
 * @return false
 */
bool Pharser::check_issucceed() const // 检查是否分析成功
{
    return this->is_succeed;
}

/**
 * @brief check that if c is a alpha
 *
 * @param c
 * @return true
 * @return false
 */
bool Pharser::is_alpha(const char &c) const
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else
        return false;
}

/**
 * @brief check that if c is a number
 *
 * @param c
 * @return true
 * @return false
 */
bool Pharser::is_num(const char &c) const // 判断当前字符是不是数字
{
    if ((c >= '0' && c <= '9'))
        return true;
    else
        return false;
}

/**
 * @brief print output to both command and log.txt
 *  add timestamp to it;
 * @param output
 */
void Pharser::debug(const string &output) // 在出现错误时输出行数和提示信息，并将is_success修改为0
{
    time_t now = time(nullptr);
    char *curr_time = ctime(&now);
    log << curr_time;
    // cout << curr_time;
    cout << "Compilation error!" << endl;
    log << "Compilation error!" << endl;
    cout << "line " << line << ": " << output << endl;
    log << "line " << line << ": " << output << endl;
    this->is_succeed = 0;
}

/**
 * @brief read line begin with let
 *
 * @return int
 */
int Pharser::read_let() // 读取用户自定义变量
{
    if (!this->statename.empty())
    {
        add_states();
    }
    if (buffer[1] != 'e' || buffer[2] != 't') // 识别let
    {
        return let_error;
    }
    else
    {
        int i = afterlet;
        while (buffer[i] == ' ') // let之后可以有多个空格，会被忽略过去
        {
            i++;
        }
        if (buffer[i] != '_' && !is_alpha(buffer[i]))
        {
            return name_error;
        }
        else // 字母或下划线开头
        {
            string mainId;
            int j = i + 1;

            while (is_num(buffer[j]) || is_alpha(buffer[j]) || buffer[j] == '_')
                j++;
            mainId.assign(this->buffer + i, j - i); // 将变量名保存为字符串Id

            info();
            log << "read variable name succeed! mainId = " << mainId << endl;
            if (mainId != "username") // 子属性配置
            {
                if (this->username.empty())
                {
                    return letisner_error;
                }
                i = j;
                while (buffer[i] == ' ') // 忽略所有空格
                    i++;
                if (buffer[i] != '=') // 没有读取到想要的'='
                {
                    info();
                    log << "there isn't a =, instrad of a " << buffer[i] << endl;
                    return assign_error;
                }
                else // 读取value，添加到record里面，返回处理结果
                {
                    info();
                    log << "get \'=\' succeed!" << endl;
                    return (read_value(i + 1, mainId));
                }
            }
            else // username配置
            {
                if (!this->username.empty()) // 如果当前正在处理另一个用户的信息，则结束处理
                {
                    info();
                    log << "add the last " << this->username << "'record" << endl;
                    this->add_records();
                }
                i = j;
                while (buffer[i] == ' ')
                    i++;
                if (buffer[i] != '=')
                {
                    info();
                    log << "there isn't a \'=\', instead of a \'" << buffer[i] << '\'' << endl;
                    return assign_error;
                }
                else // 读取
                {
                    info();
                    log << "begin to read value" << endl;
                    return (read_string_value(i + 1));
                }
            }
        }
    }
}

/**
 * @brief 读取赋值给变量的字符串或数字
 *
 * @param begin buffer中的起始位置
 * @param mainId 变量名
 * @return int
 */
int Pharser::read_value(const int &begin, const string &mainId) // 读取赋给变量的值
{
    int i = begin;
    while (buffer[i] == ' ')
        i++;
    if (buffer[i] != '\"' && !is_num(buffer[i])) // 处理不是字符串也不是数字的情况
    {
        info();
        log << "there isn't a normal \" or number" << endl;
        return value_error;
    }
    else if (buffer[i] == '\"')
    {
        int j = i + 1;
        while (j < maxsize && !(buffer[j] == '\"' && buffer[j - 1] != '\\') && buffer[j] != '\n')
        {
            j++;
        }
        if (j == maxsize || buffer[j] != '\"')
            return stringend_error;
        else
        {
            string value(buffer + i + 1, j - i - 1);
            info();
            log << "read value succeed! " << value << endl;
            this->record.add_string(mainId, value);
            i = j + 1;
        }
    }
    else if (is_num(buffer[i]))
    {
        int num = 0;
        do // 读取数字，存储到num中
        {
            num = num * 10 + (buffer[i] - '0');
            i++;
        } while (is_num(buffer[i]));
        this->record.add_num(mainId, num);
    }
    while (i < maxsize && buffer[i] == ' ') // 忽略空格
    {
        i++;
    }
    if (buffer[i] == '\n' || buffer[i] == '#' || buffer[i] == 0) // 检测行尾
    {
        return succeed;
    }
    else
    {
        return end_error;
    }
}

/**
 * @brief read value to assign username
 *
 * @param begin
 * @return int
 */
int Pharser::read_string_value(const int &begin) // 读取赋给username的值
{
    int i = begin;
    while (buffer[i] == ' ')
        i++;
    if (buffer[i] != '\"') // 处理字符串
    {
        info();
        log << "there isn't a normal \", instead of a \'" << buffer[i] << '\'' << endl;
        return uservalue_error;
    }
    else
    {
        i++;
        int j = i;
        while (j < maxsize && !(buffer[j] == '\"' && buffer[j - 1] != '\\') && buffer[j] != '\n')
            j++;
        if (buffer[j] != '\"')
        {
            info();
            log << "there isn\'t a \", instead of a \'" << buffer[j] << '\'' << endl;
            return stringend_error;
        }
        else
        {
            string value(buffer + i, j - i);
            this->username = value;
            i = j + 1;
        }
        while (i < maxsize && buffer[i] == ' ') // 忽略末尾的空格
        {
            i++;
        }
        info();
        log << "read value succeed! value = " << this->username << endl;
        if (buffer[i] == '\n' || buffer[i] == '#' || buffer[i] == 0) // 忽略行尾的注释
        {
            return succeed;
        }
        else
        {
            log << "there is " << int(buffer[i]) << buffer[i] << "in the end" << endl;
            return end_error;
        }
    }
}

/**
 * @brief add record to pharser tree and clear last username and record
 *
 */
void Pharser::add_records() // 添加记录到分析树中并清空当前username和record
{
    records.insert(make_pair(this->username, this->record));
    this->username.clear();
    this->record.clear_it();
}

int Pharser::read_state()
{
    if (!this->statename.empty()) // 将处理的上一个状态存进分析树中
    {
        // cout << "statename = " << this->statename << endl;
        int error_num = this->add_states();
        if (error_num == invalid_error)
        {
            return invalid_error;
        }
    }
    if (buffer[1] != 't' || buffer[2] != 'a' || buffer[3] != 't' || buffer[4] != 'e')
    {
        return state_error;
    }
    else
    {
        // 读取状态名
        int i = afterstate;
        while (i < maxsize && buffer[i] == ' ')
        {
            i++;
        }
        if (!is_alpha(buffer[i]))
        {
            info();
            log << "statename isn\'t start with alpha" << endl;
            return statename_error;
        }
        else
        {
            int j = i + 1;
            while (j < maxsize && is_alpha(buffer[j]))
            {
                j++;
            }
            string name(buffer + i, j - i);
            this->statename = name;
            info();
            log << "read statename succeed! " << statename << endl;
            while (j < maxsize && buffer[j] == ' ') // 忽略空格
            {
                j++;
            }
            if (buffer[j] != '\n' && buffer[j] != '#' && buffer[j] != 0)
            {
                return end_error;
            }
            else
            {
                info();
                log << "read state succeed" << endl;
                return succeed;
            }
        }
    }
}

int Pharser::add_states() // 添加记录到states里面，并删除statename和state信息
{
    if (this->state.check_valid() && !this->state.check_conjumpneed() && !this->state.check_defaultneed() && !this->state.check_need())
    {
        this->states.insert(make_pair(this->statename, this->state));
        this->statename.clear();
        this->state.clear_it();
        return succeed;
    }
    else
    {
        info();
        log << "is_valid = " << this->state.check_valid() << ", need_input = " << this->state.check_need()
            << ", need_default = " << this->state.check_defaultneed() << ", need_conjump = " << this->state.check_conjumpneed() << endl;
        return invalid_error;
    }
}

int Pharser::read_step()
{
    int i = aftertable;
    info();
    log << "begin to read step, the first char is " << (int)buffer[i] << buffer[i] << endl;
    if (buffer[i] == 'O') // Output
    {
        if (buffer[i + 1] != 'u' || buffer[i + 2] != 't' || buffer[i + 3] != 'p' || buffer[i + 4] != 'u' || buffer[i + 5] != 't')
        {
            return step_error;
        }
        i += afteroutput;
        while (buffer[i] == ' ') // 跳过Output之后的空格
            i++;
        if (buffer[i] != '\"')
        {
            return output_error;
        }
        else
        {
            i++;
            int j = i;
            while (j < maxsize && !(buffer[j] == '\"' && buffer[j - 1] != '\\') && buffer[j] != '\n')
            {
                j++;
            }
            if (buffer[j] != '\"')
                return stringend_error;
            else
            {
                string output(buffer + i, j - i);
                Output actout(output);
                this->alloutputs.push_back(actout);
                this->state.addstep("Output", this->alloutputs.size() - 1);
            }
        }
    }
    else if (buffer[i] == 'E') // Exit
    {
        if (buffer[i + 1] != 'x' || buffer[i + 2] != 'i' || buffer[i + 3] != 't')
        {
            return step_error;
        }
        else
        {
            this->state.putit_valid();
            this->state.reducecon_need();
            this->state.reducedefault_need();
            Exit needexit;
            this->allexits.push_back(needexit);
            this->state.addstep("Exit", this->allexits.size() - 1);
        }
    }
    else if (buffer[i] == 'W') // Waitinput
    {
        if (buffer[i + 1] != 'a' || buffer[i + 2] != 'i' || buffer[i + 3] != 't' || buffer[i + 4] != 'i' || buffer[i + 5] != 'n' || buffer[i + 6] != 'p' || buffer[i + 7] != 'u' || buffer[i + 8] != 't')
        {
            return step_error;
        }
        if (this->state.check_need())
        {
            return nottimeout;
        }
        else
        {
            this->state.putit_need();
            this->state.addcon_need();
            Waitinput waiting;
            this->allwaitings.push_back(waiting);
            this->state.addstep("Waitinput", this->allwaitings.size() - 1);
        }
    }
    else if (buffer[i] == 'J') // Jump
    {
        if (buffer[i + 1] != 'u' || buffer[i + 2] != 'm' || buffer[i + 3] != 'p')
        {
            return step_error;
        }
        i += afterjump;
        while (buffer[i] == ' ')
            i++;
        string condition;
        if (buffer[i] == '\"') // 读取跳转条件
        {
            i++;
            int j = i;
            while (j < maxsize && buffer[j] != '\n' && !(buffer[j] == '\"' && buffer[j - 1] != '\\'))
            {
                j++;
            }
            if (buffer[j] != '\"')
            {
                return condition_error;
            }
            else
            {
                condition.assign(buffer + i, j - i);
                i = j + 1;
                while (buffer[i] == ' ')
                {
                    i++;
                }
            }
        }
        info();
        log << "read condition succeed! " << condition << endl;
        int j = i;
        if (!is_alpha(buffer[j]))
        {
            return statename_error;
        }
        while (is_alpha(buffer[j]))
        {
            j++;
        }
        string nextstate(buffer + i, j - i);
        if (!condition.empty()) // 有条件跳转
        {
            Jump jump(condition, nextstate);
            this->state.adddefault_need(); // 需要设定默认
            this->state.reducecon_need();  // 满足了对有条件跳转的需求
            i = j;
            while (j < maxsize && buffer[j] == ' ')
                j++;
            if (buffer[j] != '\n' && buffer[j] != '#' && buffer[i] != 0)
            {
                return end_error;
            }
            this->alljumps.push_back(jump);
            this->state.addstep("Jump", this->alljumps.size() - 1);
        }
        else
        {
            Jump jump(nextstate);
            this->state.putit_valid();    // 这个状态可以正常退出
            this->state.reducecon_need(); // 即便没有有条件跳转也没关系了
            i = j;
            while (j < maxsize && buffer[j] == ' ')
                j++;
            if (buffer[j] != '\n' && buffer[j] != '#' && buffer[i] != 0)
            {
                return end_error;
            }
            this->alljumps.push_back(jump);
            this->state.addstep("Jump", this->alljumps.size() - 1);
        }
    }
    else if (buffer[i] == 'D') // Default
    {
        if (buffer[i + 1] != 'e' || buffer[i + 2] != 'f' || buffer[i + 3] != 'a' || buffer[i + 4] != 'u' || buffer[i + 5] != 'l' || buffer[i + 6] != 't')
        {
            return step_error;
        }
        this->state.reducecon_need(); // 即便没有条件跳转也没关系了
        this->state.reducedefault_need();
        this->state.putit_valid();
        i += afterdefault;
        while (buffer[i] == ' ')
            i++;
        if (buffer[i] != '\"')
        {
            return not_info;
        }
        i++;
        int j = i;
        while (j < maxsize && !(buffer[j] == '\"' && buffer[j - 1] != '\\') && buffer[j] != '\n')
        {
            j++;
        }
        string infoout;
        if (buffer[j] != '\"')
            return stringend_error;
        else
        {
            infoout.assign(buffer + i, j - i);
        }
        info();
        log << "read infoout succeed!" << infoout << endl;
        i = j + 1;
        while (i < maxsize && buffer[i] == ' ' && buffer[i] != '\n')
            i++;
        if (!is_alpha(buffer[i]))
        {
            log << "the statename isn\'t start with an alpha, instead of a " << buffer[i] << endl;
            return statename_error;
        }
        j = i + 1;
        while (j < maxsize && is_alpha(buffer[j]))
        {
            j++;
        }
        string nextstate(buffer + i, j - i);
        info();
        log << "read nextstate succeed! " << nextstate << endl;
        while (j < maxsize && buffer[j] == ' ')
        {
            j++;
        }
        if (buffer[j] != '#' && buffer[j] != '\n' && buffer[j] != 0)
        {
            info();
            log << "the last char is " << (int)buffer[j] << buffer[j] << endl;
            return end_error;
        }
        Default notcondition(infoout, nextstate);
        this->alldefaults.push_back(notcondition);
        this->state.addstep("Default", this->alldefaults.size() - 1);
    }
    else if (buffer[i] == 'T') // Timeout
    {
        if (buffer[i + 1] != 'i' || buffer[i + 2] != 'm' || buffer[i + 3] != 'e' || buffer[i + 4] != 'o' || buffer[i + 5] != 'u' || buffer[i + 6] != 't')
        {
            return step_error;
        }
        int expire_time = 0;
        i += aftertimeout;
        while (buffer[i] == ' ')
            i++;
        if (!is_num(buffer[i]))
            return time_error;
        else
        {
            while (is_num(buffer[i]))
            {
                expire_time = expire_time * 10 + (buffer[i] - '0');
                i++;
            }
        }
        info();
        log << "read number succeed! " << expire_time << endl;
        if (buffer[i] != ' ')
        {
            info();
            log << "there isn\'t a \' \' after expire_time." << endl;
            info();
            log << "there is a " << buffer[i] << endl;
            return time_error;
        }
        while (buffer[i] == ' ')
            i++;
        int j = i;
        if (!is_alpha(buffer[i]))
        {
            info();
            log << "statename isn\'t start with a aplha, instead of a " << buffer[i] << endl;
            return statename_error;
        }
        else
        {
            while (is_alpha(buffer[j]))
            {
                j++;
            }
        }
        string nextstate(buffer + i, j - i);
        Timeout timeout(expire_time, nextstate);
        this->alltimeous.push_back(timeout);
        this->state.addstep("Timeout", this->alltimeous.size() - 1);
        this->state.reduceinput_need();
        while (buffer[j] == ' ')
        {
            j++;
        }
        if (buffer[j] != '\n' && buffer[j] != '#' && buffer[j] != 0)
            return end_error;
    }
    else if (buffer[i] == 'C')
    {
        if (buffer[i + 1] != 'o' || buffer[i + 2] != 'm' || buffer[i + 3] != 'p' || buffer[i + 4] != 'a' || buffer[i + 5] != 'r' || buffer[i + 6] != 'e')
        {
            return step_error;
        }
        i += aftercompare;
        while (buffer[i] == ' ')
            i++;
        if (buffer[i] != '$')
        {
            info();
            log << "the variable isn\'t start with \'$\'" << endl;
            return variable_error;
        }
        else
        {
            i++;
            int j = i + 1;
            if (!is_alpha(buffer[i]) && buffer[i] != '_')
            {
                info();
                log << "the variablename is error, the first char is " << buffer[i] << endl;
                return variable_error;
            }
            else
            {
                while (is_alpha(buffer[j]) || is_num(buffer[j] || buffer[j] == '_'))
                    j++;
            }
            string variable(buffer + i, j - i);
            info();
            log << "read variablename succeed! " << variable << endl;
            i = j;
            while (i < maxsize && buffer[i] == ' ')
                i++;
            int oper;
            // read operator
            if (buffer[i] == '<')
            {
                if (buffer[i + 1] == '=')
                {
                    oper = lessequal;
                    i += 2;
                }
                else
                {
                    oper = lesser;
                    i++;
                }
            }
            else if (buffer[i] == '>')
            {
                if (buffer[i + 1] == '=')
                {
                    oper = biggerequal;
                    i += 2;
                }
                else
                {
                    oper = bigger;
                    i++;
                }
            }
            else if (buffer[i] == '=')
            {
                oper = equalit;
                i++;
            }
            else if (buffer[i] == '!')
            {
                if (buffer[i + 1] != '=')
                {
                    return oper_error;
                    i += 2;
                }
                else
                {
                    oper = notequal;
                    i += 2;
                }
            }
            else
                return oper_error;
            info();
            log << "read operator succeed! " << oper << endl;
            while (i < maxsize && buffer[i] == ' ')
                i++;
            if (buffer[i] == 't' && buffer[i + 1] == 'o') // read to
            {
                i += 2;
            }
            else
            {
                info();
                log << "there isn\'t a \"to\", instead of a " << buffer[i];
                return to_error;
            }
            while (buffer[i] == ' ')
                i++;
            string nextstate;
            j = i;
            if (!is_alpha(buffer[i]))
                return statename_error;
            else
            {
                while (is_alpha(buffer[j]))
                    j++;
            }
            nextstate.assign(buffer + i, j - i);
            info();
            log << "read nextstate succeed! " << nextstate << endl;
            while (buffer[j] == ' ')
            {
                j++;
            }
            if (buffer[j] != '\n' && buffer[j] != '#' && buffer[j] != 0)
                return end_error;
            Compare compare(variable, oper, nextstate);
            this->allcompares.push_back(compare);
            this->state.addstep("Compare", this->allcompares.size() - 1);
        }
    }
    else if (buffer[i] == '$') // read Compute
    {
        i++;
        int j = i;
        if (buffer[i] != '_' && !is_alpha(buffer[i]))
        {
            return variable_error;
        }
        else
        {
            j++;
            while (buffer[j] == '_' || is_alpha(buffer[j]) || is_num(buffer[j]))
                j++;
        }
        string variable(buffer + i, j - i);
        info();
        log << "read variablename succeed! " << variable << endl;
        while (j < maxsize && buffer[j] == ' ')
            j++;
        int oper;
        if (buffer[j] == '+')
        {
            oper = addit;
        }
        else if (buffer[j] == '-')
        {
            oper = reduceit;
        }
        else if (buffer[j] == '=')
        {
            oper = assignment;
        }
        else
        {
            return oper_error;
        }
        info();
        log << "read operator succeed! " << oper << endl;
        j++;

        while (j < maxsize && buffer[j] == ' ')
            i++;
        if (buffer[j] != '\n' && buffer[j] != '#' && buffer[j] != 0)
        {
            info();
            log << "the char in the end is " << (int)buffer[j] << buffer[j] << endl;
            return end_error;
        }
        Compute compute(variable, oper);
        this->allcomputes.push_back(compute);
        this->state.addstep("Compute", this->allcomputes.size() - 1);
    }
    else
    {
        return step_error;
    }
    return succeed;
}

void Pharser::out_invalid() // 输出状态不合法的提示信息
{
    info();
    string outstring = this->statename;
    outstring.append(" The status is illegal! It may not be possible to leave this state, causing an error in the program.");
    debug(outstring);
}

void Pharser::alert_enderror() // 字符串没有正确以双引号结束的提示信息
{
    info();
    debug("The string did not end properly!");
}

ostream &operator<<(ostream &out, const Pharser &pharser) // 运算符重载，输出pharser
{
    out << endl;
    out << "print the pharser tree:" << endl;
    out << "State:" << endl;
    for (const auto &state : pharser.states)
    {
        out << state.first << endl;
        // out << state.second;
    }
    for (const auto &record : pharser.records)
    {
        out << record.first << endl;
        // out << record.second;
    }
    out << "waiting:" << endl;
    for (int i = 0; i < pharser.allwaitings.size(); i++)
    {
        pharser.allwaitings[i].printit(out);
    }
    out << "exits:" << endl;
    for (int i = 0; i < pharser.allexits.size(); i++)
    {
        pharser.allexits[i].printit(out);
    }
    out << "jumps:" << endl;
    for (int i = 0; i < pharser.alljumps.size(); i++)
    {
        pharser.alljumps[i].printit(out);
    }
    out << "Defaults:" << endl;
    for (int i = 0; i < pharser.alldefaults.size(); i++)
    {
        pharser.alldefaults[i].printit(out);
    }
    out << "Timeout:" << endl;
    for (int i = 0; i < pharser.alltimeous.size(); i++)
    {
        pharser.alltimeous[i].printit(out);
    }
    out << "Compare:" << endl;
    for (int i = 0; i < pharser.allcompares.size(); i++)
    {
        pharser.allcompares[i].printit(out);
    }
    out << "Notfind:" << endl;
    out << "Compute:" << endl;
    for (int i = 0; i < pharser.allcomputes.size(); i++)
    {
        pharser.allcomputes[i].printit(out);
    }
    out << "Output:" << endl;
    for (int i = 0; i < pharser.alloutputs.size(); i++)
    {
        pharser.alloutputs[i].printit(out);
    }
    return out;
}

bool Pharser::checkit() // 检查分析树的合法性
{
    // 检查所有跳转到的状态是否有定义
    for (int i = 0; i < alljumps.size(); i++)
    {
        if (this->states.find(alljumps[i].check_nextstate()) == this->states.end())
        {
            string output;
            output += "State ";
            output += alljumps[i].check_nextstate();
            output += " is not found!";

            info();
            debug(output);
            return false;
        }
    }
    for (int i = 0; i < alldefaults.size(); i++)
    {
        if (this->states.find(alldefaults[i].checknextstate()) == this->states.end())
        {
            string output;
            output += "State ";
            output += alldefaults[i].checknextstate();
            output += " is not found!";

            info();
            debug(output);
            return false;
        }
    }
    for (int i = 0; i < alltimeous.size(); i++)
    {
        if (this->states.find(alltimeous[i].check_nextstate()) == this->states.end())
        {
            string output;
            output += "State ";
            output += alltimeous[i].check_nextstate();
            output += " is not found!";

            info();
            debug(output);
            return false;
        }
    }
    for (int i = 0; i < allcompares.size(); i++)
    {
        if (this->states.find(allcompares[i].check_nextstate()) == this->states.end())
        {
            string output;
            output += "State ";
            output += allcompares[i].check_nextstate();
            output += " is not found!";

            info();
            debug(output);
            return false;
        }
    }
    // 如果过程中用到变量，则一定要有username的赋值操作
    if (this->allcompares.size() || this->allcomputes.size())
    {
        bool hasusername = false;
        for (int i = 0; i < allcomputes.size(); i++)
        {
            log << allcomputes[i].check_variable() << endl;
            log << allcomputes[i].check_oper() << endl;
            if (allcomputes[i].check_variable() == "username")
            {
                if (allcomputes[i].check_oper() == assignment)
                    hasusername = true;
                else
                {
                    debug("username can't carryout operator except '='");
                    return false;
                }
            }
        }
        if (!hasusername)
        {
            debug("It can't define a username!");
            return false;
        }
    }
    // 检查有没有程序入口状态
    if (this->states.find("Start") == this->states.end())
    {
        debug("The script file don't have a Start state!");
        return false;
    }
    return true;
}

void Pharser::carryout() // 根据分析树，执行程序
{
    string username;
    string statename = "Start";
    string nextstate;
    string userinput;
    mutex mtx;
    while (!statename.empty())
    {
        nextstate.clear();
        lock_guard<mutex> lock(mtx);
        vector<pair<string, int>> nowsteps = this->states[statename].checksteps();
        for (int i = 0; i < nowsteps.size(); i++)
        {
            if (nowsteps[i].first == "Exit")
            {
                info();
                log << "carry out Step Exit" << endl;
                break;
            }
            else if (nowsteps[i].first == "Output")
            {
                info();
                log << "carry out Step Output" << endl;
                string output = this->alloutputs[nowsteps[i].second].checkoutput();
                printoutput(output, username);
            }
            else if (nowsteps[i].first == "Waitinput")
            {
                info();
                log << "carry out Step Waitinput" << endl;
                int pos = nowsteps[i].second;
                bool readsucceed = false;
                for (int j = i + 1; j < nowsteps.size(); j++)
                {
                    if (nowsteps[j].first == "Timeout")
                    {
                        log << "find Timeout!" << endl;
                        int timepos = nowsteps[j].second;
                        readsucceed = this->allwaitings[pos].limitiputtime(this->alltimeous[timepos].check_time());
                        if (!readsucceed) // 超时处理
                        {
                            info();
                            log << "carry out Step Timeout" << endl;
                            nextstate = this->alltimeous[timepos].check_nextstate();
                            // cout << "this->nextstate = " << this->nextstate << endl;
                        }
                        else
                        { // 顺利读取用户输入
                            info();
                            log << "read user input succeed" << endl;
                            userinput = this->allwaitings[pos].checkinput();
                            // cout << "userinput: " << this->userinput << endl;
                        }
                        break;
                    }
                }
                if (!readsucceed)
                {
                    break;
                }
            }
            else if (nowsteps[i].first == "Jump")
            {
                info();
                log << "carry out Step Jump" << endl;
                int pos = nowsteps[i].second;
                string condition = this->alljumps[pos].check_condition();
                if (!condition.empty())
                {
                    if (userinput == condition)
                    {
                        info();
                        log << "carry out condition jump" << endl;
                        log << "condition is " << condition << endl;
                        nextstate = this->alljumps[pos].check_nextstate();
                        break;
                    }
                    else
                        continue;
                }
                else
                {
                    info();
                    log << "carry out no condition jump" << endl;
                    nextstate = this->alljumps[pos].check_nextstate();
                    break;
                }
            }
            else if (nowsteps[i].first == "Default")
            {
                info();
                log << "carry out Step Default" << endl;
                int pos = nowsteps[i].second;
                string output = this->alldefaults[pos].checkoutput();
                printoutput(output, username);
                nextstate = this->alldefaults[pos].checknextstate();
                break;
            }
            else if (nowsteps[i].first == "Timeout")
            {
                continue;
            }
            else if (nowsteps[i].first == "Compute")
            {
                info();
                log << "carry out Compute" << endl;
                int pos = nowsteps[i].second;
                string variable = this->allcomputes[pos].check_variable();
                int oper = this->allcomputes[pos].check_oper();
                info();
                log << "the variable to be compute is " << variable << endl;
                info();
                log << "operator is ";

                if (variable == "username" && oper == assignment)
                {
                    log << "=" << endl;
                    username = userinput;
                }
                else
                {
                    if (oper == assignment)
                    {
                        log << "=" << endl;
                        this->records[username].add_string(variable, userinput);
                    }
                    else
                    {
                        int inputnum = 0;
                        for (int i = 0; i < userinput.length(); i++)
                        {
                            inputnum = inputnum * 10 + userinput[i] - '0';
                        }
                        if (oper == reduceit)
                        {
                            log << "-" << endl;
                            this->records[username].reductit(variable, inputnum);
                        }
                        else if (oper == addit)
                        {
                            log << "+" << endl;
                            this->records[username].addit(variable, inputnum);
                        }
                    }
                }
            }
            else if (nowsteps[i].first == "Compare")
            {
                info();
                log << "carry out Step Compare" << endl;
                int pos = nowsteps[i].second;
                string variable = this->allcompares[pos].check_variable();
                int oper = this->allcompares[pos].check_oper();
                string thenextstate = this->allcompares[pos].check_nextstate();
                info();
                log << "the variable to be compare is " << variable << endl;
                info();
                log << "the operator to be use is ";
                switch (oper)
                {
                case lesser:
                    log << "<";
                    break;
                case bigger:
                    log << ">";
                    break;
                case lessequal:
                    log << "<=";
                    break;
                case biggerequal:
                    log << ">=";
                    break;
                case equalit:
                    log << "=";
                    break;
                case notequal:
                    log << "!=";
                    break;
                }
                log << endl;
                if (oper == equalit || oper == notequal) // 检验字符串
                {
                    string storestring = this->records[username].find_string(variable);
                    info();
                    log << "the string stored is " << storestring << endl;
                    info();
                    log << "the string that user input is " << userinput << endl;
                    if (!storestring.empty()) // 字符串
                    {
                        if ((storestring == userinput && oper == equalit) || (storestring != userinput && oper == notequal))
                        {
                            info();
                            log << "string hit the condition" << endl;
                            nextstate = thenextstate;
                            break;
                        }
                        continue;
                    }
                }
                int inputnum = 0;
                for (int i = 0; i < userinput.length(); i++)
                {
                    inputnum = inputnum * 10 + userinput[i] - '0';
                }
                int comparenum = this->records[username].find_num(variable);
                if ((inputnum == comparenum && oper == equalit) || (inputnum != comparenum && oper == notequal) || (comparenum < inputnum && oper == lesser) || (comparenum > inputnum && oper == bigger) || (comparenum <= inputnum && oper == lessequal) || (comparenum >= inputnum && oper == biggerequal))
                {
                    info();
                    log << "num hit the condition" << endl;
                    nextstate = thenextstate;
                    break;
                }
                info();
                log << "don't hit the condition" << endl;
            }
        }
        statename = nextstate;
        log << endl;
    }
}

int Pharser::printvariable(const int &i, const string &output, const string &username) // 从records中查找变量并打印
{
    int j = i + 1;
    while (j < output.length() && (is_alpha(output[j]) || is_num(output[j] || output[j] == '_')))
    {
        j++;
    }
    string variablename = output.substr(i, j - i);
    info();
    log << "the variable needed to be output is " << variablename << endl;

    string character;
    if (variablename == "username")
    {
        character = username;
        // cout << "this->username = " << this->username << endl;
    }
    else
        character = records[username].find_string(variablename);
    log << "the character that is found is " << character << endl;
    if (!character.empty())
        cout << character;
    else
    {
        int num = records[username].find_num(variablename);
        cout << num;
    }
    return j - 1;
}

void Pharser::printoutput(const string &output, const string &username) // 打印脚本文件里的输出信息
{
    for (int i = 0; i < output.length(); i++)
    {
        if (output[i] != '$')
        {
            if (output[i] == '\\' && i + 1 < output.length() && output[i + 1] == '"') // 跳过转义字符
            {
                continue;
            }
            cout << output[i];
        }
        else
        {
            i++;
            i = printvariable(i, output, username);
        }
    }
    cout << endl;
}

void Pharser::info() // 打印时间戳
{
    auto now = chrono::system_clock::now();
    time_t nowc = chrono::system_clock::to_time_t(now);
    tm *local_time = localtime(&nowc);
    log << put_time(local_time, "%H:%M:%S") << " ";
}