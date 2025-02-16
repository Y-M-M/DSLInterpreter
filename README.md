# DSL_Interpreter

## 什么是DSL

领域特定语言（Domain Specific Language，DSL）可以提供一种相对简单的文法，用于特定领域的业务流程定制。本作业要求定义一个领域特定脚本语言，这个语言能够描述在线客服机器人（机器人客服是目前提升客服效率的重要技术，在银行、通信和商务等领域的复杂信息系统中有广泛的应用）的自动应答逻辑，并设计实现一个解释器解释执行这个脚本，可以根据用户的不同输入，根据脚本的逻辑设计给出相应的应答。

## 脚本语言语法
1. 注释
   - 以'#'开头，'#'之后的内容都会被忽略
   - 可以置于行首或行尾，不能出现在一行代码中间
2. State
   - 定义
     - State <statename>
     - 其中statename只能由大写或小写字母构成
   - 其后可接若干行Step
   - 规范
     - 脚本编写者需保证程序一定有State Start状态，作为程序入口
     - 需要保证每一个State都能在有限的时间内离开，整个程序在无用户输入的情况下一定会在有限时间内结束，解释器会对此进行检查
3. Record
   - 定义
     - let <variablename> <value>
     - 其中variablename可以以字母或下划线开头，由数字、字母或下划线构成
     - value只能是整数或字符串，字符串需要用双引号包裹
     - let username = ""开头，作为主属性，后面可接任意条其他属性的定义
   - 规范
     - 每条记录都要有username这个属性作为主键
     - 变量引用时需要 $<varialbename>，定义时则不需要
4. Step
   - 定义
     - 以四个空格开头(注意不能是'\t')
   - 可定义操作
     - Output "<输出内容>"
       - 可用于输出变量
     - Exit
       - 退出程序
     - Waitinput
       - 等待用户输入
       - 一定要有与之对应的Timeout
       - 可以紧跟其后对用户输入进行操作，如Compare, Compute等
     - Jump (<condition>) <nextState>
       - condition可有可无，如果有的话，将用最近的用户输入来与condition进行比较(如果在此之前未定义用户输入，将用空串进行比较)，如果相等，则状态跳转到nextState；如果没有的话，直接跳转到nextState
       - 如果有条件跳转的话，一定要有Default
     - Default "<输出内容>" nextstate
       - <输出内容>为输出给用户的提示信息
       - nextstate为跳转到的下一状态
     - Timeout <时间(s)> <nextState>
       - 等待<时间(s)>时间后，如果没有用户输入，则跳转到nextstate状态
       - 注意，如果前面没有需要Timeout的Waitinput，将永远不会使用此条Timeout，也不会报错
     - $<variablename> +|-|=
       - 其中+|-只能对数字类型的变量进行操作
       - =既可以对数字类型的变量也可以对字符串类型的变量进行操作，相当于赋值运算
     - Compare $<variablename> <|>|<=|>=|=|!= <nextState>
       - 其中<|>|<=|>=只能对整型变量使用，=|!=可以对所有变量使用
5. 其他规范
   - 脚本文件中不能使用中文，请全部使用英文来编写
   - 行首不能有多余的字符，但行末和单词之间可以任意设置空格，没有限制
6. 特别说明
   - 如果使用之前没有声明的变量，则会自动生成该变量，默认为0，请尽量避免
   - 如果脚本文件不设定输入用户名的过程，则无法查找记录，任何变量都会在运行时被创建，默认为0，请尽量避免
   - 请确保程序不会不断的从状态A跳转至状态A，否则会陷入死循环，解释器不会对此进行检查
   - 所有输出中均可以包含变量，$<variablename>将被替换为变量的值，但$<variablename>之后需要以' '与其他单词隔开

## 实现
- Interpreter类
  - build()函数负责解释脚本文件构造语法树
  - 私有成员变量负责存储语法树
  - carryout()函数负责执行程序
- Record类
  - 负责存储所有的脚本文件中定义的变量以及运行过程中新使用的变量
- State类
  - 负责存储该状态的所有Step所在的位置
- Step类
  - 负责存储每个step所拥有的信息，定义其行为

## 测试
- cmake+gtest进行测试
- 共十个测试点
  - Recordtest 测试record中对记录增、删、改、查的函数
  - Computetest, Comparetest, Defaulttest, Jumpttest, Outputtest, Timeouttest 对相应Step中的成员函数的检查
  - Pharsertest 对脚本文件中出现的常见错误及对应的输出进行检查
  - Concurrencytest 进程并发测试，5个进行并发执行carryout函数，不添加用户输入，等待30s后均进行超时处理，检查能否正常结束和输出
- CMAKE_CXX_FLAGS检查内存是否泄漏

## 程序运行说明
1. 编译
   - cd build
   - cmake ..
   - make
2. 测试
   - ctest(在build目录下使用)
3. 运行
   - ./DSLInterpreter
   - 根据提示输入脚本文件路径
   - 根据提示进行操作