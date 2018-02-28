/*
题目描述
The gray code is a binary numeral system where two successive values 
differ in only one bit.
Given a non-negative integer n representing the total number of bits 
in the code, print the sequence of gray code. A gray code sequence must 
begin with 0.
For example, given n = 2, return[0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note: 
For a given n, a gray code sequence is not uniquely defined.
For example,[0,2,3,1]is also a valid gray code sequence according to 
the above definition.

题目解读：
格雷码中，两个连续的数，只有一个比特位不同。给定一个整数n代表格雷码的
比特位个数，输出格雷码序列。格雷码序列必须从0开始。
解题思路：
当n=1时，为[0,1]
当n=2时，为[00,01,11,10]
当n=3时，为[000,001,011,010,110,111,101,100]
由此可以看出新的序列其实是在前面序列基础上插入新的值
其中前半部分的数值首位补零，后半部分的数值为前半部分数高位变1，逆向插入
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i = 0; i < n; i++)  //依次生成1~n个比特位时的格雷码
        {
            const int high_bit = 1 << i;  //左移，使得最高位为1
            for(int j = result.size() - 1; j >= 0; --j)
            {
                result.push_back(high_bit | result[j]);
            }
        }
        return result;
        
    }
};