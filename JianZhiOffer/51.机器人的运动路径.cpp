/********************************************************************************
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，
上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，
当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
解题思路：回溯法
每次访问一个位置，当前位置可以访问，即坐标的数位之和不大于阈值，计数加1，并且访问它周围的
四个位置；若不能访问就回退到上一步。
********************************************************************************/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows < 1 || cols < 1)
            return 0;
        bool* visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        visited = NULL;
        return count;
    }
    
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        int count = 0;
        if(check(threshold, rows, cols, row, col, visited))  //若当前位置可以访问
        {
            visited[row * cols + col] = true;
            count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                + movingCountCore(threshold, rows, cols, row, col + 1, visited);
        }
        return count;
    }
    bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
    {
        if(row >= 0 && row < rows && col >= 0 && col < cols     
          && getDigitSum(row) + getDigitSum(col) <= threshold
          && !visited[row * cols + col])
            return true;
        return false;
    }
    
    int getDigitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    
};