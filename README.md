# DataLab

## 项目编译与环境指南

本实验要求环境安装好 `gcc`, `make` 和 `python3`。

C 语言编译环境

```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install gcc-multilib
```

Python 编译环境，我们演示 Virtualenv 下的配置方法，如果你使用 Conda 可以自行配置类似的环境出来

```bash
sudo apt-get update
sudo apt-get install python3 python3-pip python3-venv
python3 -m venv venv
source venv/bin/activate
pip install pycparser -i  https://mirrors.aliyun.com/pypi/simple/
```

如果你想获得 VSCode 的最佳代码提示体验，请指定 `cStandard` 为 `gnu99`:

```json
{
    "C_Cpp.default.cStandard": "gnu99"
}
```

### 如何编译

```bash
make
```

## 实验简述

本实验考察对数的二进制表示和位运算的认识。具体来说，本实验会给出多个函数要求实现，比如求两个数的异或，但你只能用限制范围内的位运算操作符（有时候允许更多）。

我们的题目和你们要完成的函数都在 [`bits.c`](./bits.c) 文件中。

### 一个例子

```c
/* 
 * bitAnd - x & y using only ~ and |
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ |
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}
```

如在 `bitAnd` 题目中，你需要修改代码，使得：

1. 保证函数的返回值符合要求
2. 保证只使用了 Legal ops 中给出的符号
3. 符号数的总数不能超过 Max ops

### 具体要求

你被允许：

- 对于整型题目，即 `float_i2f` 之前的题目，你被允许定义 `int` 变量，即不能定义 `unsigned`，除非题目允许
- 对于浮点数题目，即 `float_i2f` 及之后的题目，你被允许定义 `int` 和 `unsigned` 的变量

你被禁止：

- 禁止使用控制流语句，比如 `if`, `else`, `for`, `while`，除非题目允许
- 禁止使用函数，或调用任何函数
- 禁止使用宏
- 禁止使用非位运算符号，比如 `&&`, `||`, `-`, `?:`,`!`, `>`, `==` 除非题目允许
- 禁止定义其他类型的变量，比如 `float`，`char`，结构体，数组，联合体等
- 禁止使用类型转换，比如 `(float)x` 和 `(int)(1.0f)`
- 禁止使用任何浮点常量，比如 `1.0f`，当然你可以使用它的二进制形式代表的整数，注意不要违反上一条规则
- 禁止使用 Undefined Behavior，比如对一个 32 位数逻辑右移超过 31 位，你应该假设我们的机器会在这时候返回不确定的结果，不得利用 Undefined Behavior，以免我们跨平台编译的时候结果不一致

其他事项：

- 符号数计数不包括等号 `=`。

### 如何评测

```bash
source venv/bin/activate
python3 test.py
```

我们提供了一个 `test.py` 脚本，当你完成实验时可以在你自己机器上直接运行该指令。如果出现最大操作数、合规性错误会直接显示错误信息到屏幕上，而正确性信息则会被记录在 `result.txt` 文件中。
需要注意，只有当你 `bits.c` 文件编译没有问题（即不存在语法问题）时，`test.py` 才会显示你答题的相关信息

### 如何使用我们提供的工具

#### btest

```bash
./btest -h # 查看 btest 的其他功能
```

#### ishow

```bash
./ishow 0x27
Hex = 0x00000027,	Signed = 39,	Unsigned = 39
```

#### fshow

```bash
./fshow 0x15213243
Floating point value 3.255334057e-26
Bit Representation 0x15213243, sign = 0, exponent = 0x2a, fraction = 0x213243
Normalized.  +1.2593463659 X 2^(-85)
```

### 最终得分

DataLab 本次设置为通过性实验，即测试点通过则为满分。

### 实验报告

报告模版见 [`report/report.md`](report/report.md)，同时你还需要阅读 [`report/README.md`](report/README.md)。

### 提交

将仓库 push 到上游 Github 仓库里即可完成提交。

## 注意事项

1. 不允许抄袭，助教会将每个人代码同网上代码和其他同学代码进行查重
2. 报告需要写清楚做题思路，否则会酌情扣分
3. 慎用代码格式化工具，如果一定要使用，请用 .clang-format 文件
