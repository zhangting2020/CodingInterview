/*
题目描述
Given a number represented as an array of digits, plus one to the number.
题目解读：
给定一个数组，其中每个数都表示一个数的一位，比如{1,2,3,4}表示1234，给这个大数加1.
解题思路：
从数组的低位开始加1，进位标志为0或1。
1.当该位的和大于9，则进位=1，否则为0；
2.当进位为0时，返回最终结果。
  当进位为1时，继续计算更高位
  
3.需要注意的是，最高位可能产生进位，因此若最高位产生了进位，需要将结果位数扩展。
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1; //进位
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            if(carry == 0)
                return digits;
        }
        if(carry)
            digits.insert(digits.begin(),1);
        return digits;
    }
};