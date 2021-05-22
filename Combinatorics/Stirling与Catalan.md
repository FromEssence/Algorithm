## Stirling数

### 1. 引入

将n个数分为k个非空集合的方法数。对k进行sigma求和则得到"贝尔数"，即集合划分为非空子集的总方法数。



### 实战例题

#### 1. 第二类Stirling

1. HDU 2512 裸题
2. HDU 2643 加上需要对顺序进行排列

#### 2. 第一类

1. HDU 3625
2. HDU 4372

## Catalan数

### 1. 求解方法

### 2. 典型问题[3]
1. 正确的入栈和出栈顺序。从这个问题本身就可以推出C(2n,n)-C(2n,n+1)，大体思路是用`1`表示入栈操作，`0`表示出栈，所有可能的排列减去不符合要求的排列数[1]。
	这包含了许多具体场景。如：
	* 从1~n的n个数字入栈，有多少种出栈序列？
	* n个左括号和n个右括号，有多少种正确的排列方式？回想，如果使用栈判断给定括号序列是否符合要求，那么左括号对应的就是入栈，右括号对应出栈。
	* 给定n个X和n个Y，组成Dyck words的数量。(X对应入栈，Y对应出栈)
	* 有2n个人排成一行进入剧场。入场费 5 元。其中只有n个人有一张 5 元钞票，另外n人只有 10 元钞票，剧院无其它钞票，问有多少中方法使得只要有 10 元的人买票，售票处就有 5 元的钞票找零？
	* 正方格从左下到右上，不穿越对角线，曼哈顿路线的个数
2. 保持先后顺序不变，对n+1个数字进行n次划分[4]
	* 有n+1个叶子的有根满二叉树的个数
	* 满足结合律的n+1个连乘因子的不同计算顺序，因为这样才正好有n次乘法
3. n个元素进行non-crossing划分，划分方法总数。注意！这不是普通的划分数, 贝尔数才是集合划分数目, 且有C(n)<=B(b)

### 3. 实战例题



### 参考
1. 《组合数学及应用》哈工大
2. [Catalan ppt](https://math.mit.edu/~rstan/transparencies/china.pdf)
3. [cp-algorithm](https://cp-algorithms.com/combinatorics/catalan-numbers.html)
4. [Catalan wiki](en.wikipedia.org/wiki/Catalan_number#Applications_in_combinatorics)
5. https://chgtaxihe.top/2020/06/24/%E6%96%AF%E7%89%B9%E6%9E%97%E6%95%B0/
6. https://www.whitman.edu/mathematics/cgt_online/book/section01.08.html
7. https://math.stackexchange.com/questions/1572788/catalan-numbers-vs-bell-numbers
8. 

