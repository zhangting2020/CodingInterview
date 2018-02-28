/*
题目描述
Given a sorted array, remove the duplicates in place such that each 
element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in 
place with constant memory.
For example,
Given input array A =[1,1,2],
Your function should return length =2, and A is now[1,2].
解题思路：
给定一个排序数组，删除其中的重复元素。
解题思路：
1.i = 0, j = 1,开始访问数组元素。
2.若相等，则j++，跳过重复元素
3.不相等，则i++,将j所在位置的值赋给i.
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int i = 0;
        for(int j = 1; j < n; ++j)
        {
            if(A[i] != A[j])
            {
                ++i;
                A[i] = A[j];
            }
        }
        return i + 1;
    }
};