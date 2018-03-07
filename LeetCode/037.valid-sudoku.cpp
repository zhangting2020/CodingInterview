/*
题目描述
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character'.'.
题目解读：
判断一个数独是否有效。规则：每一行，每一列，每9个方阵里，1-9的数字只能出现一次。
空的格子被填充为“.”，只填充了部分的数独也是有效的。
解题思路：
1. 使用9×9的row，col，box数组，分别表示行，列，和子box里，数字是否重复出现了。出现记为true。
比如，row[0][3]表示第0行是否出现过4（因为数组的索引只能是0-8），col[0][3]表示第0列是都出现过4，
box[0][3]表示第0号box是否出现过4。
2. 将9×9的网格划分为9个子box。k = i / 3 * 3 + j / 3，可以将任意一个（i,j）位置映射到索引为0-8的子box里。
比如（5,6）：k = 5 / 3 * 3 + 6 / 3 = 5.这个位置在索引为5的box里。
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;  
                    int k = i / 3 * 3 + j / 3;
                    if(row[i][num] || col[j][num] || box[k][num])
                        return false;
                    row[i][num] = col[j][num] = box[k][num] = true;
                }
            }
        }
        return true;
        
    }
};