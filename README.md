# DataLab

## 项目编译与环境指南

本实验要求环境安装好 `gcc`, `make` 和 `python3`。
```
sudo apt-get update #更新 安装指令
sudo apt-get install build-essential #配置gcc、make
sudo apt-get install gcc-multilib #配置32位兼容库
```

<!-- TODO: 到底要安装哪些，在哪个系统上做过测试？ -->

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
- 禁止使用非位运算符号，比如 `&&`, `||`, `-`, `?:`,`!`, `>` 除非题目允许。需要注意，当题目允许使用if、else的时候，“==”的出现是合法的（samesign除外），而剩下的逻辑运算符需要看题目要求
- 禁止定义其他类型的变量，比如 `float`，`char`，结构体，数组，联合体等
- 禁止使用类型转换，比如 `(float)x` 和 `(int)(1.0f)`
- 禁止使用任何浮点常量，比如 `1.0f`，当然你可以使用它的二进制形式代表的整数，注意不要违反上一条规则

<!-- TODO: 允许创建 unsigned 的变量吗，你考虑了吗，原 lab 里是禁止的 -->

其他事项：

- 符号数计数不包括等号 `=`。

### 如何评测

```
python test.py
```

我们提供了一个 `test.py` 脚本，当你完成实验时可以在你自己机器上直接运行该指令。如果出现最大操作数、合规性错误会直接显示错误信息到屏幕上，而正确性信息则会被记录在 `result.txt` 文件中。

### 如何使用我们提供的工具

#### btest

<!-- TODO: -->
```
make clean #清除之前的可执行文件
make #进行编译
./btest #显示出哪些题目在正确性上出现问题
```

#### ishow
使用例子
<!-- TODO: -->
```
make clean
make
./ishow 0x27
```
此时你会发现显示出
```
Hex = 0x00000027,	Signed = 39,	Unsigned = 39
```
#### fshow
使用例子
<!-- TODO: -->
```
make clean
make
./fshow 0x15213243
```
此时你会发现显示出
```
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

<!-- TODO: 我们统一一下代码格式化的格式，用 .clang-format 里的，如果你不知道怎么用，你就把自动格式化关了 -->
