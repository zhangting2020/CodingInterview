/****************************************************************************
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
解题思路：
        异常判断：底数为0，指数小于0，不合法
		把负指数先转换为正指数，求指数运算结果
		若指数为负，则结果为 result = 1.0 / result;
*****************************************************************************/

class Solution {
public:
    double Power(double base, int exponent) {
        if(abs(base - 0.0) < 1e-6 && exponent < 0)  //底数为0，指数小于0，不合法
            return 0;
        unsigned int absExp;
        if(exponent < 0)
            absExp = -exponent;
        else
            absExp = exponent;
        double result = 1.0;
        for(int i = 1; i <= absExp; ++i)
        {
            result *= base;
        }
        
        if(exponent < 0)
            result = 1.0 / result;
        return result;
    }
};