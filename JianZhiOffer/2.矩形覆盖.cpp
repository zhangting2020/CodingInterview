/*******************************************************
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

解题思路：斐波拉契数列。若第一块砖竖放，有f(n-1)种摆法，若第一块砖横放，则有f(n-2)种摆法
		  所以f(n) = f(n-1) + f(n-2)
********************************************************/

class Solution {
public:
    int rectCover(int number) {
        if(number <= 2)
            return number;
        int minusone = 2, minustwo = 1;
        int result = 0;
        for(int i = 2; i < number; ++i)
        {
            result = minusone + minustwo;
            minustwo = minusone;
            minusone = result;
        }
        return result;

    }
};