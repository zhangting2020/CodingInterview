/*
题目描述
Given an array S of n integers, find three integers in S such that the sum is closest to a given 
number, target. Return the sum of the three integers. You may assume that each input would have 
exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
题目解读：
给定n个整数数组S，找到其中任意3个整数，它们的和最接近给定的目标值。返回这三个数的和，假设只有一个解。
解题思路：
1. 初始化result = num[0] + num[1] + num[2]（任意的，只要是数组中三个数），并对数组按递增的规则排序
2. i = 0 : n - 3  
   设定两个指针分别从i的下一位start及数组尾部end向中间查找：
      若i，start和end位置的和比target小，说明应该增大这三个位置的和，使和更接近target，所以start++;
	  否则，说明和太大了，为了逼近target，end--;
	  判断当前的sum-target和之前的result-target哪个更接近target，更新result。
*/
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int n = num.size();
        int result = num[0] + num[1] + num[2]; //初始化结果
        sort(num.begin(), num.end());
        for(int i = 0; i < n - 2; ++i)
        {
            int start = i + 1, end = n - 1;
            while(start < end)
            {
                int sum = num[i] + num[start] + num[end];
                if(sum < target)
                    ++start;
                else
                    --end;
                
                if( abs(sum - target) < abs(result - target) )
                    result = sum;
            }
        }
        return result;
    }
};