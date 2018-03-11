/*
题目描述
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
题目解读：
给定行数，生成Pascal三角形
解题思路：观察三角形，每一行第一个和最后一个元素都是1，下一行间隙上的数字，是上一行两个相邻数的和。
每一行的数字个数等于行数 index + 1。定义curRow存储当前行的数字。
1.当前行全部初始化为1。
2.第二行开始，执行以下操作：
  for 1 : index - 1
     result[index - 1][i - 1] + result[index - 1][i];
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for(int index = 0; index < numRows; ++index)
        {
            vector<int> curRow(index + 1, 1); //初始化当前行全为1
            for(int i = 1; i < index; ++i)  //计算第2到倒数第二个数字
                curRow[i] = result[index - 1][i - 1] + result[index - 1][i];
            result.push_back(curRow);
        }
        return result;
    }
};
  