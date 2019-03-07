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

## L1-004 计算摄氏温度 （5 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805142086336512)

[C++ (5/5)](https://github.com/Heliovic/GPLT/blob/master/L1-004/main.cpp)

## L1-005 考试座位号 （15 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805140211482624)

[C++ (15/15)](https://github.com/Heliovic/GPLT/blob/master/L1-005/main.cpp)

## L1-006 连续因子 （20 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805138600869888)

[C++ (20/20)](https://github.com/Heliovic/GPLT/blob/master/L1-006/main.cpp)

### 解题思路

若 N 是质数，则显然只有 N 本身。

否则，对每个 i <= sqrt (N)，检查从 i 开始的连续的数之积是否能整除 N。记录下最长的连续数起止位置并取最长。

## L1-007 念数字 （10 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805136889593856)

[C++ (10/10)](https://github.com/Heliovic/GPLT/blob/master/L1-007/main.cpp)

## L1-008 求整数段和 （10 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805135224455168)

[C++ (10/10)](https://github.com/Heliovic/GPLT/blob/master/L1-008/main.cpp)

## L1-009 N个数求和 （20 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805133597065216)

[C++ (20/20)](https://github.com/Heliovic/GPLT/blob/master/L1-009/main.cpp)

### 解题思路

分数化简与求和。

## L1-010 比较大小 （10 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805132040978432)

[C++ (10/10)](https://github.com/Heliovic/GPLT/blob/master/L1-010/main.cpp)

### 解题思路

注意 ```while (scanf("%d", &t) != EOF)``` 的写法。

## L1-011 A-B （20 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805130426171392)

[C++ (20/20)](https://github.com/Heliovic/GPLT/blob/master/L1-011/main.cpp)

### 解题思路

散列。

## L1-012 计算指数 （5 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805128870084608)

[C++ (5/5)](https://github.com/Heliovic/GPLT/blob/master/L1-012/main.cpp)

### 解题思路

快速幂。

## L1-013 计算阶乘和 （10 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805127389495296)

[C++ (10/10)](https://github.com/Heliovic/GPLT/blob/master/L1-013/main.cpp)

## L2-001 紧急救援 （25 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805073643683840)

[C++ (25/25)](https://github.com/Heliovic/GPLT/blob/master/L2-001/main.cpp)

### 解题思路

Dijkstra。这里使用 path_num[i] 来记录从起点到 i 有多少条最短路。path_num 的更新逻辑：

```cpp
if (dis[i] > dis[u] + graph[u][i])
{
    // ...
    path_num[i] = path_num[u];
}
else if (dis[i] == dis[u] + graph[u][i])
{
    // ...
    path_num[i] += path_num[u];
}
```

还要注意在 Dijkstra 算法中，若某轮找不到新的 u，说明剩余未访问的点不在与起始点同一个连通分量中，应直接返回： 
https://github.com/Heliovic/GPLT/blob/master/L2-001/main.cpp#L62 

此题还可以使用 Dijkstra + DFS。使用 ```vector<int> path[MAX_N]``` 记录所有前驱后 DFS 获得所有路径。

## L2-002 链表去重 （25 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805072641245184)

[C++ (25/25)](https://github.com/Heliovic/GPLT/blob/master/L2-002/main.cpp)

### 解题思路

散列打表，链表操作。

## L2-003 月饼 （25 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805071789801472)

[C++ (25/25)](https://github.com/Heliovic/GPLT/blob/master/L2-003/main.cpp)

### 解题思路

贪心方法。

## L2-004 这是二叉搜索树吗？ （25 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805070971912192)

[C++ (25/25)](https://github.com/Heliovic/GPLT/blob/master/L2-004/main.cpp)

### 解题思路

二叉树的构建、遍历。

## L2-005 集合相似度 （25 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805070149828608)

[C++ (25/25)](https://github.com/Heliovic/GPLT/blob/master/L2-005/main.cpp)

### 解题思路

STL set 的使用。注意，若使用如下代码读取 set 会附加拷贝的时间，导致超时：

```cpp
set<int> s1, s2;
s1 = sts[t1];
s2 = sts[t2];
```

正确的做法是，使用指针:

```cpp
set<int> *s1, *s2;
s1 = &sts[t1];
s2 = &sts[t2];
```

## L2-006 树的遍历 （25 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805069361299456)

[C++ (25/25)](https://github.com/Heliovic/GPLT/blob/master/L2-006/main.cpp)

### 解题思路

二叉树重建。

## L3-001 凑零钱 （30 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805054207279104)

[C++ (30/30)](https://github.com/Heliovic/GPLT/blob/master/L3-001/main.cpp)

### 解题思路

0-1背包问题，动态规划。

## L3-002 特殊堆栈 （30 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805053695574016)

[C++ (30/30)](https://github.com/Heliovic/GPLT/blob/master/L3-002/main.cpp)

### 解题思路

用 vector 模拟堆栈、二分查找。

## L3-003 社交集群 （30 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805053141925888)

[C++ (30/30)](https://github.com/Heliovic/GPLT/blob/master/L3-003/main.cpp)

### 解题思路

并查集。

## L3-004 肿瘤诊断 （30 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805052626026496)

[C++ (30/30)](https://github.com/Heliovic/GPLT/blob/master/L3-004/main.cpp)

### 解题思路

BFS。

## L3-005 垃圾箱分布 （30 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805052131098624)

[C++ (30/30)](https://github.com/Heliovic/GPLT/blob/master/L3-005/main.cpp)

### 解题思路

Dijkstra。

## L3-007 天梯地图 （30 分）

[Problem description](https://pintia.cn/problem-sets/994805046380707840/problems/994805051153825792)

[C++ (27/30)](https://github.com/Heliovic/GPLT/blob/master/L3-007/main.cpp)

### 解题思路

Dijkstra + DFS。【测试点 4】答案错误。
