/*
题目描述
Given a m x n matrix, if an element is 0, set its entire row and 
column to 0. Do it in place.
click to show follow up.
Follow up:
Did you use extra space?
A straight forward solution using O(m n) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
题目解读：
给定m * n的数组，如果一个元素是0，设置它所在的整行和整列的元素为0。
解题思路：
如果某个位置的元素为0，就将它所在的行的首元素和列的首元素设为0.
特别的，由于第一行和第一列都共用矩阵第一个元素，所以为第0列设置一个单独
的标志col0.
例如数组
1 2 0 3                   0 0 0 3
2 0 1 4  经过设置得到：   0 0 1 4  同时col0 = 1.第一行第一列的元素不为0
1 3 4 5                   1 3 4 5
接着从右下角向上访问数组，当该元素所在的行或者列的首元素为0，
设置其为0；第一列单独处理，若col0为0时，才表明目前这一行的第一列的元素
应该为0.
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        
        for(int i = 0; i < rows; ++i)
        {
            if(matrix[i][0] == 0) 
                col0 = 0;
            for(int j = 1; j < cols; ++j) //首列已经由col0的状态表示了
            {
                if(matrix[i][j] == 0) 
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        //从右下角开始设置0
        for(int i = rows - 1; i >= 0; --i)
        {
            for(int j = cols - 1; j >= 1; --j) //注意单独处理首列
            {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col0 == 0)
                matrix[i][0] = 0;
        }
    }
};
