/**************************************************************************
题目描述
Given n non-negative integers a1 , a2 , ..., an , where each represents a point
at coordinate (i, ai ). n vertical lines are drawn such that the two endpoints of 
line i is at (i, ai ) and (i, 0). Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.
Note: You may not slant the container.
题目解读：
数组中的数值为线的高度。找到两条线，与x轴构成的容器能容纳的水最多。
解题思路：
构成的容器容积由两条线之间的距离，和两天线中的短边决定。
1.两个指针，分别指向最左和最右的高度；
2.每次改变最短的边的指针的指向，使其向中间移动
3.计算当前的面积：短边 * 两条线的距离，并与之前的距离对比保存最大面积
*****************************************************************************/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        if(height.empty())
            return max_area;
        int left = 0;
        int right = height.size() - 1;
        int curArea = 0;
        int curHeight = 0;
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                curArea = height[left] * (right - left);
                left++;
            }
            else
            {
                curArea = height[right] * (right - left);
                right--;
            }
            max_area = max(max_area, curArea);
        }
        return max_area;
    }
};

