
题目描述
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note: 
You may assume that A has enough space to hold additional elements from B. 
The number of elements initialized in A and B are m and n respectively.
题目解读：
给定两个排序数组A和B，把B合并到A。假设A有足够长的空间。A的元素为m，B的为n。
解题思路：
由于数组A有足够的空间，因此合并后A的长度应该为m+n。把未经确定的位置成为无序位置。
两个数组从从后向前访问，index_A = m - 1, index_B = n - 1，每次把更大的那个数放在最后一个无序的位置。
合并数组的作引从i = m + n - 1开始。
1.若 index_A >= 0 && index_B >= 0
  将更大的数放在A[i]，相应的数组索引-1。
2.若1不满足：
  若index_B >= 0，将B中剩下的数放入A中。
*/
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index_A = m - 1, index_B = n - 1, i = m + n - 1;
        while(index_A >= 0 && index_B >= 0)
        {
            A[i--] = A[index_A] > B[index_B] ? A[index_A--] : B[index_B--];
        }
        while(index_B >= 0)  //B中还有未归位的数
            A[i--] = B[index_B--];
    }
};
   