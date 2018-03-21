
题目描述
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. 
(each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
题目解读：
给定两个单词，找到把word1转变为word2的最少步数。每种操作记为1步。3种操作：插入，删除，替换
解题思路:
1. 状态： dp[i][j]表示将word[0,...i-1]转换到word2[0,j-1]需要的编辑距离
2. 递推关系：
    如果 word1[i-1] == word[j-1]，则dp[i][j] = dp[i-1][j-1]，等于转换到前一个字符需要的距离
　　如果 word1[i-1] != word2[j-1]
　　　　dp[i][j] = min(dp[i-1][j-1] + 1 //表示用word2[j-1]替换word1[i-1]
　　　　　　　　,dp[i-1][j] + 1 //表示删除，将word1[0,...i-2]转换到word2[0,...j-1],然后删word1[i-1]
　　　　　　　　,dp[i][j-1] + 1)//表示增加,将word1[0,i-1]转换为word2[0,j-2]，然后插入Word2[j-1]
3. 初始化：
　　dp[i][0] = i; i = 1...m; 相当于word1转换为空串
　　dp[0][j] = j; j = 1...n; 相当于把空串转换为Word2