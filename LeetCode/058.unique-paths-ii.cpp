/*
题目描述
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is2.
Note: m and n will be at most 100.
题目解读：
在网格中加入障碍，标识为1。每次只能向右或者下走，计算有多少条路径。
解题思路：
动态规划。到达点(i,j)的路径数为path[i][j]，而到达某个点只有两种方式：从该点上方path[i-1][j]，或者
从该点左方p[i][j-1]。因此到达某个点的路径数为：p[i][j] = p[i-1][j] + p[i][j-1].
注意：可以用m*n的矩阵保存路径值，但是每次只用到两个点的值，因此优化为用单列保存。path[m]的一列空间
保存路径数，某一位置上方路径数是path[i-1]，而左方路径为path[i]。
主要步骤如下：
1.如果当前位置i的是障碍，则当前位置路径数清零，path[i] = 0;
2.如果当前位置不是障碍：
  考虑到第0行每个位置的路径数总是等于前一位置路径数，因此不用更新；
  其余位置更新规则：path[i] += path[i-1]
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();  //行，列数
        vector<int> path(m, 0);
        if(obstacleGrid[0][0] == 1 || m == 0)  //出发位置为障碍或者矩阵为空
            return 0;
        path[0] = 1;
        for(int j = 0; j < n; ++j)
        {
            for(int i = 0; i < m; ++i)
            {
                if(obstacleGrid[i][j] == 1)  //是障碍
                    path[i] = 0;
                else if(i != 0) 
                    path[i] += path[i-1];
            }
        }
        return path[m-1];
    }
};
