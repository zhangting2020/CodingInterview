/*
题目描述
Write an efficient algorithm that searches for a value in an m x n 
matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the 
previous row.
For example,
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target =3, return true.
题目解读：
给定一个数组，和一个目标值，判断数组中是否有该目标值。
数组每一行都是从左到右递增排序，后一行的第一个数比前一行的最后一个大。

解题思路：
从左下角向右上角搜索。
1.当目标值大于数组中的值时，在当前行中向右搜索。
2.当目标值小于数组中的值时，向上一行搜索。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int Rows = matrix.size();
        int Cols = matrix[0].size();
        int row = Rows - 1;
        int col = 0;
        while(row >= 0 && col <= Cols - 1)
        {
           if(matrix[row][col] == target)
               return true;
            else if(matrix[row][col] < target)
                ++col;
            else if(matrix[row][col] > target)
                --row;
        }
        return false;
    }
};

