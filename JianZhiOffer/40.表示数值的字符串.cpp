/******************************************************************************************************
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
解题思路：
1.首位如果是符号位，先去除掉符号位，再判断剩下的字符
2.如果剩下的字符全是数字，则为数值，返回真；否则继续进行
3.判断是否为小数或指数；小数的判断需要注意"123.45e+6"这种形式，指数的判断需要注意1E-16这种形式
*******************************************************************************************************/
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == NULL)
            return false;
        if(*string == '+' || *string == '-')
            ++string;
        while(*string != '\0' && *string >= '0' && *string <= '9')
            ++string;
        if(*string == '\0')  //全是数字
            return true;
        return isFraction(string) || isExponent(string);
        
    }
    bool isExponent(char *string)
    {
        if(string == NULL || *string == '\0')
            return false;
        if(*string == 'e' || *string == 'E')
        {
            ++string;  
            if(*string == '+' || *string == '-')  //1E-16这种形式
                ++string;
        }
        return isAllNum(string);
    }
    
    bool isFraction(char* string)  //"123.45e+6"
    {
        if(string == NULL || *string == '\0')
            return false;
        if(*string == '.')
            ++string;
        while(*string != '\0' && *string >= '0' && *string <= '9')
            ++string;
        if(*string == '\0') //小数点后全是数字
            return true;
        else 
            return isExponent(string); //判断是不是指数，"123.45e+6"这一种形式
            
    }
    
    bool isAllNum(char* string)
    {
        if(string == NULL || *string == '\0')
            return false;
        while(*string != '\0')
        {
            if(*string < '0' || *string > '9') //不是数字字符
                return false;
            ++string;
        }
        return true;
    }

};