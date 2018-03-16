/*
题目描述
Given a string containing just the characters'(',')','{','}','['and']', determine if the input string 
is valid.
The brackets must close in the correct order,"()"and"()[]{}"are all valid but"(]"and"([)]"are not.
题目解读：
给定一个string，包含的都是左右括号，判断string是不是合法的，左右括号形式要一一对应。
解题思路：
1.如果字符串长度是奇数，一定不是合法的，因为总会有一个字符没有被匹配。
2.字符串长度为偶数时，遇到任何左括号就入栈它对应的右括号，直到遇到右括号：
  若栈为空，说明无匹配的左括号，false
  若栈不为空，弹出栈顶，判断与当前的右括号是否匹配，匹配则访问下一个；否则false
  如果访问完整个字符串，栈为空，说明全部匹配成功，则true;否则false
*/
class Solution {
public:
    bool isValid(string s) {
        if( s.length() % 2 != 0 )//字符个数为奇数
            return false;
        stack<char> RBrackets;
        for(string::iterator it = s.begin(); it != s.end(); ++it)
        {
            if(*it == '(')
                RBrackets.push(')');
            else if(*it == '[')
                RBrackets.push(']');
            else if(*it == '{')
                RBrackets.push('}');
            else if( RBrackets.empty() || *it != RBrackets.top() ) 
            {//当出现右括号，栈为空时；  或者栈不为空而栈顶与当前右括号不匹配
                return false;
            }
            else
                RBrackets.pop();
        }
        return RBrackets.empty();  //访问完所有的，如果栈为空，则匹配完
    }
};