/****************************************************************************************************
题目描述:例如，“student. a am I”。正确的句子应该是“I am a student.”
解题思路:先饭庄整个句子，然后翻转每一个单词
注意：1.如果只有一个单词，不构成句子，不用翻转
      2.当要反转的单词恰好是句子末尾的单词时，注意边界条件
******************************************************************************************************/

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty() || !IsSentence(str))  //如果字符串为空或者只有一个单词即不是句子
            return str;
        //翻转整个句子
        reverse(str, 0, str.length() - 1);
        //翻转每一个单词
        size_t begin = 0, end = 0;
        while(end <= str.length() - 1)
        {
            if(str[begin] == ' ')
                end = ++begin;
            if(str[end] == ' ' || end == str.length() - 1)  //遇到空格或者end指向了句子最后一个单词的末尾
            {
                if(end < str.length() - 1)
                    reverse(str, begin, end - 1);  //当是句子中间的单词时，翻转单词要去掉空格
                else
                    reverse(str, begin, end);  //恰好是最后一个句末的单词，end指向的是最后一个字符
                begin = ++end;
            }
            if(str[end] != ' ')  //不是空格则找单词结尾
                ++end;
        }
        return str;
        
    }
    void reverse(string& str, int begin, int end)
     {
         if(str.empty() || begin >= end)
             return;
         while(begin < end)
         {
             char temp = str[begin];
             str[begin] = str[end];
             str[end] = temp;
             ++begin;
             --end;
         }
     }
    bool IsSentence(string str)
    {
        if(str.length() == 0)
            return false;
        size_t i = 0;
        while(i < str.length())
        {
            if(str[i] == ' ')
                return true;
            ++i;
        }
        return false;
    }
};