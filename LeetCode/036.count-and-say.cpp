/*
题目描述
The count-and-say sequence is the sequence of integers beginning as follows:
 1.     1
 2.     11
 3.     21
 4.     1211
 5.     111221 
 6.     312211
 7.     13112221
 8.     1113213211
 9.     31131211131221
 10.   13211311123113112211
1 is read off as"one 1"or 11.
11 is read off as"two 1s"or 21.
21 is read off as"one 2, then one 1"or 1211.
Given an integer n, generate the n th sequence.
Note: The sequence of integers will be represented as a string.
Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
题目解读：
读上一个字符串中连续的1和2的个数，比如从第二个开始，上一个是1个1，读作“11”；
第三个字符串读第二个字符串为两个1，所以是“21”，接下来以此类推。

解题思路：
迭代地去计算每一次的字符串。当输入为n时，要通过迭代依次得到前n-1个字符串，才能得到第n个字符串。
具体算法是在循环中执行以下操作：
tmp：存放本次的字符串，初始化为空。访问前一个字符串每一个位置：
1.若当前位置的字符与前一个位置相同，count++,i++，直到字符串被读取完或者是出现相邻的字符不同 
2.将count转换为字符t，tmp = tmp + t + ans[i-1];
3.继续访问字符串剩下的部分，把重复的数依次读出。
*/
class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)
            return "";
        string result = "1";
        for(int i = 1; i < n; ++i)
        {
            countAndSayCore(result);
        }
        return result;
    }
    
    void countAndSayCore(string &ans)
    {
        string tmp = "";
        int i = 1;
        while(i <= ans.size())
        {
            int count = 1;
            while(i < ans.size() && ans[i] == ans[i - 1])  //字符串还未访问完，且当前的字符与前一个字符相同
            {
                ++count;
                ++i;
            }
            char t = '0' + count; //将count转换为字符
            tmp = tmp + t + ans[i - 1];
            ++i;
        }
        ans = tmp;
    }
};