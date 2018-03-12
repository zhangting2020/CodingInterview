/*
题目描述
Write a function to find the longest common prefix string amongst an array of strings.
题目解读：
在字符串数组中查找最长的公共前缀字符串。{leets,leetcode，leet, leeds}，返回lee
解题思路：
先对vector中的string排序，排序后第一个和最后一个相差最远：leeds, leet, leetcode, leets
因此比较这两个字符串找到最长公共前缀。

*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty())
            return "";
        sort(strs.begin(), strs.end());
        int sz = strs.size(),length = min(strs[0].size(),strs[sz-1].size());
        for(int i = 0; i < length; ++i)
        {
            if(strs[0][i] != strs[sz - 1][i])
                return strs[0].substr(0, i);
        }
        return strs[0].substr(0, length);
    }
};