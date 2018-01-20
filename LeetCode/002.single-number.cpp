/*************************************************************************
题目描述
Given an array of integers, every element appears twice except for one. Find that single one.
Note: 
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
解题思路：
异或
*************************************************************************/
class Solution {
public:
    int singleNumber(int A[], int n) {
        for(int i = 1; i < n; ++i)
        {
            A[0] ^= A[i];
        }
        return A[0];
    }
};