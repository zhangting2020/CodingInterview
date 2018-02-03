/*******************************************************************
题目描述
Find the contiguous subarray within an array (containing at least 
one number) which has the largest sum.
For example, given the array[−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray[4,−1,2,1]has the largest sum =6.
More practice:
If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, 
which is more subtle.
题目解读：
计算连续子向量的最大和
解题思路：
          current 记录当前累加和， maxsum记录最大和。
          如果current不是正数，则丢弃掉这个和，因为它对增大和没有贡献。因此：
		  1. current <= 0，则更新current为下一个要加的数字
		  2. current > 0，则使current加上下一个要加的数字
		  3. 若 current > maxsum，则maxsum = current;
*********************************************************************/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxsum = A[0];
        int current = 0;
        for(int i = 0; i < n; ++i)
        {
            if(current <= 0)
                current = A[i];
            else
                current += A[i];
            if(maxsum < current)
                maxsum = current;
        }
        return maxsum;
    }
};