/*
题目描述
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent 
numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is11(i.e., 2 + 3 + 5 + 1 = 11).
Note: 
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of 
rows in the triangle.
题目解读：
给定一个三角形，找到从顶部到底部的最小路径和。每一步可以向想下一行相邻位置走。
解题思路：
假设当前位置为（i,j）与它相邻的下一行位置为（i+1,j）和（i+1,j+1）两个位置。则该位置的最小路径为：
minpath[i][j] = min(minpath[i+1][j], minpath[i+1][j+1]) + triangle[i][j]。采用自底向上的方法：
               
         [2],                 [2],              
        [3,4],              [3, 4],            [2],
       [6,5,7],      ==>   [7, 6, 10]     ==>  [9, 10]   ==>     [11]
      [4,1,8,3]

*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        vector<int> minpath(triangle.back());  //复制最后一行
        for(int i = triangle.size() - 2; i >= 0; --i) //从倒数第二行开始向上计算
        {
            for(int j = 0; j <= i; ++j)
            {
                minpath[j] = min(minpath[j], minpath[j+1]) + triangle[i][j];
            }
        }
        return minpath[0];
    }
};