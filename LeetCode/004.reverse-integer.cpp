/*******************************************************************************
题目描述
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
解题思路：
1.如果是0，直接返回0
2.如果最后一位是0，翻转后首位不能是0
3.溢出问题，直接返回0
*********************************************************************************/
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) 
        {
            res = res * 10 + x % 10;
            x /= 10;
        }
        return (res < INT_MIN || res > INT_MAX) ? 0 : res;
    }
};