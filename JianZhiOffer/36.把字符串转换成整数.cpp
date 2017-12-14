/************************************************************************************************************
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0

解题思路：
1.正负号一般位与数字开头，因此首先判断字符串首位，如果是符号位，则记录
2.对除去符号位的字符串进行数字的转换 result = result * 10 + sign * (str[start] - '0')
3.当字符串中有非数字字符应返回0
*************************************************************************************************************/

class Solution {
public:
    int StrToInt(string str) {
        if(str.length() == 0)
            return 0;
        bool minus = false;
        size_t start = 0;
        size_t end = str.length() - 1;
        if(str[0] == '-')
        {
            minus = true;  //为负数
            ++start;
        }
            
        if(str[0] == '+')
            ++start;
        int result = StrToIntCore(str, start, end, minus);
        return result;
        
    }
    
    int StrToIntCore(string str, size_t start, size_t end, bool minus)
    {
        if(str[start] == '\0' || start > end)
            return 0;
        int result = 0;
        int sign = minus ? -1 : 1;  //确定符号正负
        while(start <= end) 
        {
            if(str[start] > '0' && str[start] < '9')  //为数字字符
                result = result * 10 + sign * (str[start] - '0');
            else
                return 0;
            ++start;
        }
        if( (minus && result < 0x80000000) || (!minus && result > 0x7fffffff) ) //超出int负数的范围或正数的范围
            return 0;
        return result;
    }
};