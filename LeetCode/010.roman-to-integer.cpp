/*******************************************************************************************
题目描述
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

题目解读：
给定罗马数字，转换为整数。

解题思路：
I:1 V:5 X:10 L:50 C:100 D:500 M:1000
罗马数字中，如果后面的字符比前面的小，表示加，比如600：DC;
如果后面的字符比前面的大，表示要减去当前的值，比如981：CMLXXXI = -100+1000+50+10+10+10+1
*******************************************************************************************/
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        map<char, int> m{{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, 
		{'X', 10}, {'V', 5}, {'I', 1}};
        for(int i = 0; i < s.size(); ++i)
        {
            int val = m[s[i]];
            //若已经遍历到最后一个数字，或者后一个数字比当前数字小，则加上当前值
            if(i == s.size() - 1 || m[s[i + 1]] <= m[s[i]])
                res += val;
            else
                res -= val; 
        }
        return res;
    }
};