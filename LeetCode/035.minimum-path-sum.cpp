/*
题目描述
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which 
minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
题目解读：
给定m×n的网格，填充了非负整数，从左上角到右下角寻找一条路径，是的这条路径的和最小。
解题思路：
思路一：到达一个位置，只能是从当前位置的上方或者左方来的。对于一个位置（i，j）上的路径和，就等于前一
个拥有最小值的位置加当前位置的值，因此`S[i][j] = min(S[i - 1][j], S[i][j - 1]) + grid[i][j]`。但是第一
行和第一列要单独处理，因为它们中每一个位置的前一个位置只能是一个方向的。需要`m×n`的空间。

思路二：
基于前一种思路，每一次实际只需要更新`sum[i][j]`，因此只需要`sum[i - 1][j]`（在当前列上），
以及`sum[i][j - 1]`（在当前行上），所以其实只需要两列，分别存储前一列每个位置上的路径和，和当前列的
每个位置的路径和。 pre存储前一列的值，cur存储当前列的值，`cur[i - 1]`代表了当前位置的上方，`pre[i]`
代表了当前位置左方，` cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];`。

思路三：基于二的思路，保持`pre`是为了使用`pre[i]`。其实在`cur`更新前，保存`cur[i]`就是下一次计算时需
要的`pre[i]`。所以只需要一列向量。以下代码基于第三种方法实现。
*/
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> cur(m, grid[0][0]); //初始化cur
        for(int i = 1; i < m; ++i)
        {
            cur[i] = cur[i - 1] + grid[i][0];  //第一列元素上每个位置，只能是从上方到达的，因此单独计算
        }
        for(int j = 1; j < n; ++j) //从第2列元素开始，逐列计算
        {
            cur[0] = cur[0] + grid[0][j];  //每一列的第一个元素，到达的方向是左方
            for(int i = 1; i < m; ++i)
            {
                cur[i] = min(cur[i], cur[i - 1]) + grid[i][j];
            }
        }
        return cur[m - 1];
    }
};

