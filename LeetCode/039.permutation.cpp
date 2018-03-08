/*
题目描述：
Given a collection of numbers, return all possible permutations.
For example,
[1,2,3]have the following permutations:
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], and[3,2,1].
题目解读：
给定一个数组，将其中的数进行组合，求所有的组合。
解题思路：
分而治之的思想。首先将数组分成两部分，第一部分包含第一个数字1，剩下的部分包含2和3。
1. 将第一部分数字与剩下的部分中每一个位置交换，得到123,213,321
2. 对剩下未处理的部分继续分为两部分，则123只处理23,划分为2和3，同样采用1中的方式交换
得到132，其他的类似。可以看出应该使用递归的方式。
*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.empty())
            return result;
        Permutation(num，result, 0);
        return result;
    }
    
    void Permutation(vector<int> &num, vector<vector<int>> &result, int pbegin)
    {
        if(pbegin == num.size() - 1)
        {
            result.push_back(num);
        }
        for(int i = pbegin; i < num.size(); ++i)
        {//交换第一部分与剩下部分每一个位置的数字
            swap(num[i], num[pbegin]);
            //递归地处理第二部分
            Permutation(num, result, pbegin + 1);
            //每一种处理完，将第一个数字还放回原位，恢复原数组
            swap(num[i], num[pbegin]);
        }
    }
};