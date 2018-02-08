/*
题目描述：
Given an integer n, generate a square matrix filled with elements 
from 1 to n 2 in spiral order.
For example,
Given n =3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
题目解读：
给一个整数n，按照螺旋的顺序，生成一个方阵，最大的数为n^2.
解题思路：
从外向内构建数组。
*/
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        int count = 1;
        int row_start = 0, row_end = n - 1;
        int col_start = 0, col_end = n - 1;
        
        while(count <= n * n)
        {
            for(int i = col_start; i <= col_end; ++i) 
                matrix[row_start][i] = count++;
            row_start++;
            for(int i = row_start; i <= row_end; ++i)
                matrix[i][col_end] = count++;
            col_end--;
            for(int i = col_end; i >= col_start; --i)
                matrix[row_end][i] = count++;
            row_end--;
            for(int i = row_end; i >= row_start; --i)
                matrix[i][col_start] = count++;
            col_start++;
        }
        return matrix;
    }
};

