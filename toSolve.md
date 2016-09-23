##一些需要解决的问题

###Hihocoder 数位DP(等式填空)

###Polya计数法（cyx论文

###Tree DP合集
[http://blog.csdn.net/liuqiyao_01/article/details/8477730](http://blog.csdn.net/liuqiyao_01/article/details/8477730)

###POJ3093(经典背包优化, 逆序

###HDOJ 1542 (矩形面积并)(分别用离散化 和 线段树来求)

###POJ次短路
=======
###Kuangbin 图论+网络流基本题
[http://www.cnblogs.com/kuangbin/p/3228371.html](http://www.cnblogs.com/kuangbin/p/3228371.html)

###做下数位DP合集
[http://blog.csdn.net/niuox/article/details/9864199](http://blog.csdn.net/niuox/article/details/9864199)

###Hihocoder offer练习赛3

###BZOJ 2839 (容斥原理)

###DP水水：[http://codeforces.com/contest/712/problem/D](http://codeforces.com/contest/712/problem/D)

###玲珑杯Round2.5题解：
###A (组合数学 | 容斥原理)
###B (很nice的DP题， 用到lowbit(i)来减小DP转移时候的枚举量)， 关于这个性质感觉很常用， 有点类似于树状数组， 将二叉树的左右两个方向标记为0
###和1，然后惊讶的发现找第i个前面一个实际上是找最后两个点分叉的位置， 实际上是最后一个1出现的位置的上面那个点是两个点的LCA。

###CF 713C:　等价转化(严格上升转化为非严格上升，而非严格上升的该问题是一个经典问题)之后的LIS, DP时候需要每层保存上一层的min值，复杂度可降到O(N^2)

###2016大连网赛1009, 补图上求最短路，因为补图的边权值都为１，可直接用bfs搞定，　维护一个set，保存当前没有扩展的点，　对queue中的当前点进行扩展

###2016青岛网赛1011,　最短路上的最小割，经典题

###2016沈阳网赛1004, 强行找关系转化为矩阵快速幂求单项，　之后求x^y%(s+1)，　考虑到y比较大，　根据欧拉定理进行转化: a^φ(x) = 1(mod x), 所以x^y%(s+1) -> x^y%φ(s+1)+φ(s+1) mod (s+1)

###大连网赛1001　非常经典的题目，burnside定理得到：F(n) = 1/n * sigma(f(gcd(i, n)))，这是一个非常经典的问题，　可以转化为： F(n) = ​1/n * ∑​ (d∣n)​​f(d)φ(​n/d​​)(训练指南有证明，按n的因子分类), 时间复杂度为O(log(n)*sqrt(n))
