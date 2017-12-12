/*********************************************************************************************************
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
解题思路：使用递归加短路求值的思想
1.ans不为零时，会执行与运算符右边的递归语句
2.ans为零时，返回0
**********************************************************************************************************/

class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));  //短路求值
        return ans;
       
    }
};