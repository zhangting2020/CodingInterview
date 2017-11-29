/**************************************************************************
题目描述：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

解题思路：
1.循环控制条件顺时针打印，可以通过行数和列数来控制循环次数，每次打印一圈。
  顺时针打印，可以通过行数和列数来控制循环次数，每次打印一圈。
  1 2 3，相当于从左向右打印第一行，循环次数：行数/2,向上取整，即1.
  如果是列[1;2;3],相当于从上向下打印一列，循环次数：列数/2，向上取整，即1；
  如果是n * m的矩阵，也是取行列一半向上取整后的最小的那一个次数，作为循环控制条件。
  
2.getMatrixInCircle函数中，row为矩阵总行数，col为矩阵总列数，start为这一次循环开始的坐标起始值
 
***************************************************************************/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int row = matrix.size(); 
        int col = matrix[0].size();
        int row_circle = ceil((double)row / 2.0);  
        int column_circle = ceil( (double)col / 2.0 );
        int circle = min(row_circle, column_circle); //循环次数选择最小的
        for(int start = 0; start < circle; ++start)  //i：行，j:列
        {
            getMatrixInCircle(result, matrix, row, col, start);  //固定第一列，打印行
        }
        return result;
    }
    
    void getMatrixInCircle(vector<int>& result, vector<vector<int> > matrix, int row, int col, int start)
    {
        int end_x = col - start - 1;  //列的尾坐标
        int end_y = row - start - 1;  //行的尾坐标
        //从左向右打印
        for(int i = start; i <= end_x; ++i)
            result.push_back(matrix[start][i]);   //第一行所有元素

        //从上向下打印
        for(int i = start + 1; i <= end_y; ++i)   //最后一列所有元素，除去首行的，因为从左向右打印过了
            result.push_back(matrix[i][end_x]); 

        //从右向左打印
        if(start < end_y)   //若相等，当前的矩阵只有一行，已经被打印过
        {
            for(int i = end_x - 1; i >= start; --i)
                result.push_back(matrix[end_y][i]);
        }
        //从下向上打印
        if(start < end_x)  //若相等，当前的矩阵只有一列，被打印过了
        {
            for(int i = end_y - 1; i > start; --i)
                result.push_back(matrix[i][start]);
        }
    }

};
