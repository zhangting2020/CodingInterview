/*******************************************************************
题目描述
Determine whether an integer is a palindrome. 
Do this without extra space.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, 
note the restriction of using extra space.
You could also try reversing an integer. 
However, if you have solved the problem "Reverse Integer", 
you know that the reversed integer might overflow. 
How would you handle such case?
题目解读：
判断一个整数是不是回文。没有额外空间。
解题思路：
由于不能用额外空间，因此不能把数字转换为字符串；
由于翻转数字，如果数字很大，有可能反转后会造成溢出。
综上，一种思路是：将数字的一半翻转。例如1221，翻转后半部分后为12，
翻转后的后半部分与前半部分一样，则为回文。
********************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || x % 10 == 0 && x != 0) //负数和10, 100...
            return false;
        int revertNum = 0;
        while(x > revertNum) //当原始数字比翻转后的后半部分数字还小，说明过半
        {
            //从最低位取每一位数字，组成翻转后的后半部分数字
            revertNum = revertNum * 10 + x % 10;
            x /= 10;
        }
        return revertNum == x || revertNum / 10 == x;
    }
};


