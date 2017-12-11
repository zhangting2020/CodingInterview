/**********************************************************************************************
题目描述：对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”
解题思路：翻转字符串
1. 首先将字符串分为两部分，前n位和剩下的字符
2. 分别反转这两个部分，得到bafedZYX
3. 再一次反转字符串，得到XYZdefab
***********************************************************************************************/
class Solution {
public:
    string LeftRotateString(string& str, int n) {
        if(str.length() == 0)
            return "";
        size_t begin = 0, end = str.length() - 1;
        //先翻转前n位
        reverse(str, begin, begin + n - 1);
        //翻转剩下的部分
        reverse(str, begin + n, end);
        //翻转整个字符串
        reverse(str, begin, end);
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
};