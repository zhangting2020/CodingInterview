/*********************************************************************
题目描述
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct 
ways can you climb to the top?
题目解读：
爬一个N阶的楼梯，每一次可以爬1步或者2步，有多少种方式可以爬到顶部。
解题思路：动态规划。到达第N阶楼梯，可以从N-1阶处走一步，也可以从N-2
阶处走两步。因此到达第N阶的方法就是这两种方法的和。
注意：当阶梯数小于等于2时，可以直接返回值
*********************************************************************/
class Solution {
public:
    int climbStairs(int n) {
		if(n <= 2)
            return n;
        int minus_1 = 1;
		int minus_2 = 2;
		int cur = 0;
		for(int i = 3; i <= n; ++i)
		{
			cur = minus_1 + minus_2;
			minus_1 = minus_2;
			minus_2 = cur;
		}
		return cur; 
    }
};