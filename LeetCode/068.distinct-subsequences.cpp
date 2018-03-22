/*
题目描述
Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie,"ACE"is a subsequence of"ABCDE"while"AEC"is not).
Here is an example:
S ="rabbbit", T ="rabbit"
Return3.
题目解读：
给定一个字符串S和T，从原始字符串S中通过删除一些字符得到T，有多少种方法。
的新的字符串。S ="rabbbit", T ="rabbit"。通过删除S中第一个，第二个，第三个b，得到三个字符串T。
解题思路：
有关字符串的子序列或者配准类的问题，首先应该考虑的就是用动态规划。
首先，若原字符串和子序列都为空时，返回1，因为空串也是空串的一个子序列；若原字符串不为空，而子序列
为空，也返回1，因为空串也是任意字符串的一个子序列；而当原字符串为空，子序列不为空时，返回0，因为非
空字符串不能当空字符串的子序列。理清这些，二维数组dp的边缘便可以初始化了：
  Ø r a b b b i t
Ø 1 1 1 1 1 1 1 1
r 0 1 1 1 1 1 1 1
a 0 0 1 1 1 1 1 1
b 0 0 0 1 2 3 3 3
b 0 0 0 0 1 3 3 3
i 0 0 0 0 0 0 3 3
t 0 0 0 0 0 0 0 3 

1. 当 T[i - 1] == S[j - 1] 时，dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1]
新的dp值可以是不使用第j个字符，却能构成T中i子串的个数dp[i][j-1]，加上不使用第j个字符能构成
T中i-1子串的个数dp[i-1][j-1]。
2. 若不等， dp[i][j] = dp[i][j - 1]
*/
class Solution {
public:
    int numDistinct(string S, string T) {
        int m = T.size(), n = S.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int j = 0; j <= n; ++j)
            dp[0][j] = 1;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(S[j-1] == T[i-1]) //因为多了一行一列，且从1开始循环，注意对应字符索引
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
