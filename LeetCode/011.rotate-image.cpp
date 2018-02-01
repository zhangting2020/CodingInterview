/**********************************************************************
题目描述
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
题目解读：
对一个方阵顺时针旋转90度。
解题思路：
1 2 3     1 4 7     7 4 1
4 5 6     2 5 8     8 5 2
7 8 9     3 6 9     9 6 3
第一步，对方阵进行转置；第二步，逐行反转。
**********************************************************************/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        //矩阵转置
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)   //从j = i的位置开始是因为i=j的位置转置时不变
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            //沿着y轴翻转,相当于逐行翻转
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};