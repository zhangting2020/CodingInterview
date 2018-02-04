/*
题目描述
A robot is located at the top-left corner of a m x n grid 
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
How many possible unique paths are there?
题目解读：
机器人在m*n的网格的左上角，机器人只能向下或者向右走，如果机器人要到右下
角，求有多少条不同的路径。
解题思路：
动态规划。到达点(i,j)的路径数为p[i][j]，而到达某个点只有两种方式：从该点
上方p[i-1][j]，或者从该点左方p[i][j-1]。因此到达某个点的路径数为：
p[i][j] = p[i-1][j] + p[i][j-1].
边界处的点路径数为1，p[0][j] = p[i][0] = 1,因此初始化所有的p[i][j] = 1.
注意：
可以用m*n的矩阵保存路径值，但是每次只用到两个点的值，因此优化为用单列保存。
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n < m)
            return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for(int j = 1; j < n; ++j)
        {
            for(int i = 1; i < m; ++i)
            {
                cur[i] += cur[i - 1];
            }
        }
        return cur[m -1];
    }
};
