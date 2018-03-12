/*
题目描述
Given an index k, return the k th row of the Pascal's triangle.
For example, given k = 3,
Return[1,3,3,1].
Note: 
Could you optimize your algorithm to use only O(k) extra space?
题目解读：
给定一个索引k，返回pascal三角形的第k行。
解题思路：
所以每一行都只与上一行有关，从后往前计算，从而避免了之前的数据被覆盖。
例如index = 4，索引为4的行的结果中共有4+1个数，先初始化为： 1 1 1 1 1；只需要更新除掉首尾元素的部分。
首先在外层循环设置更新的轮数 i = 1 ： 3，然后每次更新这一行数据时，从后往前更新，()代表被修改的元素：
i = 1: 被更新为 1 (2) 1 1 1
i = 2：被更新为 1 2 1 1 1 -> 1 2 (3) 1 1 -> 1 (3) 3 1 1
i = 3：被更新为 1 3 3 1 1 -> 1 3 3 (4) 1 -> 1 3 (6) 4 1 -> 1 (4) 6 4 1
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);  //初始化当前行全为1
        for(int i = 1; i < rowIndex; ++i)
        {
            for(int col = i; col > 0; --col)  
            {
                res[col] += res[col - 1];
            }
        }
        return res;
    }
};