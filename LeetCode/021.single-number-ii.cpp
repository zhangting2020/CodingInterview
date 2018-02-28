/*
题目描述
Given an array of integers, every element appears three times except 
for one. Find that single one.
Note: 
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
题目解读：
给定一个整数数组，除了某一个元素，其他元素都出现了3次。找到这个元素。
注意算法应该有线性时间复杂度；如果不使用额外存储空间呢？
解题思路：
00 + 1 = 01；
01 + 1 = 10;
10 + 1 = 00.
b0 = b0 xor r & ~b1;
b1 = b1 xor r & ~b0;
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, two = 0;
        for(int i = 0; i < n; ++i)
        {
            ones = ones ^ A[i] & ~two;
            two = two ^ A[i] & ~ones;
        }
        return ones;
    }
};