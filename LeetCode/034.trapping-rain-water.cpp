/*
题目描述：
Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap after 
raining.
For example, 
Given[0,1,0,2,1,0,1,3,2,1,2,1], return6.
The above elevation map is represented by 
array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 
6 units of rain water (blue section) are being trapped. 
题目解读：
给定n个非负整组成的数组代表海拔高度图，直方图间距为1，计算雨后可囤多少水。
解题思路：
1.Brute Force
- Initialize ans=0ans=0
- Iterate the array from left to right:
- Initialize max_left=0 and max_right=0
- Iterate from the current element to the beginning of array updating: 
  max_left=max(max_left,height[j])
- Iterate from the current element to the end of array updating: 
  max_right=max(max_right,height[j])
- Add min(max_left,max_right)−height[i] to ans.
2.用两个指针，从两头向中间扫描。假设右端有更高的水坝，则需水量取决于
更低的左边水坝，因此按照从左到右方向计算蓄水量；如果左边有更高的水坝，
则换方向计算。
初始化，left和right分别指向左右两端的起始位置当left<right时，执行以下步骤：
- 若height[left] < height[right]
 - 若height[left] >= left_max，更新left_max
 - 否则，ans += left_max - height[left]
 - ++left
- 否则
 - 若height[right] >= right_max，更新right_max
 - 否则，ans += right_max - height[right]
 - right--
*/

class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0)
            return 0;
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int ans;
        while(left < right)
        {
            if(A[left] < A[right])
            {
                if(A[left] >= left_max)
                    left_max = A[left];
                else
                    ans += left_max - A[left];
                ++left;
            }
            else
            {
                if(A[right] >= right_max)
                    right_max = A[right];
                else
                    ans += right_max - A[right];
                --right;
            }
        }
        return ans;
    }
};