/*
题目描述
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"
题目解读：
给定n对圆括号，生成所有格式正确当然组合。
解题思路：
回溯法。括号对数最多有n对，max = n;
cur：保存当前组合的括号
1.如果cur的长度=max*2,则将这个答案加入到最终结果中
2.如果开括号的长度<max,则增加一个开括号
3.如果闭括号的长度<开括号的长度，增加闭括号
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
    
    void backtrack(vector<string> &ans, string cur, int open, int close, int max)
    {
        if(cur.length() == max * 2)
        {
            ans.push_back(cur);
            return;
        }
        if(open < max)
            backtrack(ans, cur + "(", open + 1, close, max);
        if(close < open)
            backtrack(ans, cur + ")", open, close + 1, max);
    }
};
