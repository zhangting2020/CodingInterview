/*
题目描述
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array A =[1,1,1,2,2,3],
Your function should return length =5, and A is now[1,1,2,2,3].
题目解读：
移除重复元素，重复元素最多允许出现2次。返回最后的数组长度
解题思路：
从前向后访问数组元素，每次判断当前位置i数字与后面位置j上的数字是否相等。times为重复次数
1.i = 0, j = 1, times = 1; 
2.如果A[i] != A[j]，无论之前times是多少，都需要更新i+1位置的数，并且重置times = 1；
  因为若times > 2，则应把当前j上的元素放到下一个需要规范的位置即i+1上，重新统计重复元素。
  若times <= 2，两个位置元素不相等，j位置的元素放到下一个需要规范的位置上即i+1上。
3.如果A[i] == A[j]：++times;
      若times <= 2: 需要挪动j位置重复的元素到i+1位置上
	  否则：跳过重复元素
3.最后i的位置就是最终数组的长度，i+1得到数组长度。
另一种思路：
链接：https://www.nowcoder.com/questionTerminal/567f420f12ed4069b7e1d1520719d409
来源：牛客网

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        int index=2;//允许重复两次，可以修改为三次
        for(int i=2;i<n;i++)
        {
            if(A[i]!=A[index-2])//允许重复两次，可以修改为三次
                A[index++]=A[i];
        }
         
        return index;
    }
};
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2)
            return n;
        int i = 0, times = 1;
        for(int j = 1; j < n; ++j)
        {
            if(A[i] != A[j])  //当i与j位置不相等时，需要挪动j位置元素到i+1位上
            {
                A[++i] = A[j];
                times = 1;  //重置元素的重复次数
            }
            else
            {
                ++times;
                if(times <= 2) //重复次数未超
                {
                    A[++i] = A[j];
                }
            }
        }
        return i + 1;
    }
};