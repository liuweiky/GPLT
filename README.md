# GPLT
⚔️Group Programming Ladder Tournament

## L1-001 Hello World （5 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805147132084224)

[C++ (5/5)](https://github.com/Heliovic/GPLT/blob/master/L1-001/main.cpp)

## L1-002 打印沙漏 （20 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805145370476544)

[C++ (20/20)](https://github.com/Heliovic/GPLT/blob/master/L1-002/main.cpp)

### 解题思路

设上面的倒三角形层数为 t，中间的单个符号为第一层，则一个完整的三角形所需符号数目为 1 + 3 + 5 + ··· + 2t - 1 = t^2。所以整个沙漏需要的符号个数为 2t^2 - 1。令 2t^2 - 1 = N，即可算出最大层数和所需符号数，注意，这里都是整数运算，向下取整。之后按照符号和层数之间的函数关系打印。

## L1-003 个位数统计 （15 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805143738892288)

[C++ (15/15)](https://github.com/Heliovic/GPLT/blob/master/L1-003/main.cpp)

### 解题思路

打表。
