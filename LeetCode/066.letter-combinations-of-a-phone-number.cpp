/*
题目描述
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
题目解读：
给定一个数字字符串，返回所有可能的组合。数字和字母的映射和电话的键盘一致。
Input:Digit string "23" 
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
解题思路：
键盘映射：1：无 2:abc 3:def 4:ghi 5:jkl 6:mno 7:pqrs 8:tuv 9:wxyz
用一个字符串数字将数字和字符组映射，数组下标映射到数字，内容为字符组。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res(1, "");
        if(digits.empty())
            return res;
        string mp[12] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < digits.size(); ++i)  //遍历每一个数字
        {
            vector<string> temp;
            for(int j = 0; j < res.size(); ++j)  //遍历已经枚举过过得结果
            {
                int num = digits[i] - '0';
                for(int k = 0; k < mp[num].size(); ++k)  //给之前的每一个结果，添加上num代表的字符组
                    temp.push_back(res[j] + mp[num][k]);
            }
            res = temp;
        }
        return res;
    }
};
