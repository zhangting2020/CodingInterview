/***********************************************************************************************************
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以
出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
解题思路：递归地判断。当前位比较时，如果pattern下一位是*，有几种匹配方式
1.当前位相等，或者pattern中当前位是‘.'，则str与pattern分别向后访问下一位
2.当前位的下一位是*时，分为当前位相等，当前位为'.'，当前位不相等的情况

************************************************************************************************************/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == NULL || pattern == NULL)
            return false;
        return matchCore(str, pattern);
    }
    
    bool matchCore(char* str, char* pattern)
    {
        if(*str == '\0' && *pattern == '\0')
            return true;
        if(*str != '\0' && *pattern == '\0')
            return false;
        
        if( *(pattern + 1) == '*' )  //如果pattern当前字符下一位为*
        {
            if(*pattern == *str || (*pattern == '.' && *str != '\0') ) //当前位匹配，或者pattern当前位是‘.’
                return matchCore(str + 1, pattern + 2)    //str当前位和pattern的当前位及*完成匹配
                || matchCore(str + 1, pattern)   //str当前位匹配，由于pattern中*可以代表多位，因此pattern保持
                || matchCore(str, pattern + 2); //pattern中*前的可以忽略
            else
                return matchCore(str, pattern + 2); //当前位不相等并且后一位为*，直接跳过pattern的这两位
        }
        if(*str == *pattern || (*pattern == '.' && *str != '\0')) //当前位相等，或者为.
            return matchCore(str + 1, pattern + 1);
        
        return false;
    }
};