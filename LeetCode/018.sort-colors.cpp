/*
题目描述
Given an array with n objects colored red, white or blue, sort them 
so that objects of the same color are adjacent, with the colors in 
the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, 
white, and blue respectively.

Follow up: 
A rather straight forward solution is a two-pass algorithm using 
counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, 
then overwrite array with total number of 0's, then 1's and followed 
by 2's.

Could you come up with an one-pass algorithm using only constant space?
题目解读：
给定一个数组，里面存放物体颜色。红，白，蓝，分别用0,1,2表示。需要将数组中
物体的颜色，相同的放在一起。设计单程算法。
解题思路：
zero_index:表示0的索引；two_index:表示2的索引；i:表示当前遍历到的元素索引
0应该放在数组前面，而2应该在后面，1位于中间，因此只要把0和2放好，1就在中间。
初始时，zero_index=0,two_index = n -1.
1.如果当前元素为0，则当前值与zero_index处的元素交换，同时++zero_index,++i；
2.如果当前元素为2，则当前值与two_index处的元素交换,同时--two_index；
3.如果当前元素为1，则当前值放置不动，i指向要访问的下一个元素。
*/
class Solution {
public:
    void sortColors(int A[], int n) {
        if(n <= 0)
            return;
        int zero_index = 0;
        int two_index = n - 1;
        int i = 0;
        while(i < two_index + 1)
        {
            if(A[i] == 0)
            {
                swap(A[i],A[zero_index]);
                ++zero_index;
                ++i;
            }
            else if(A[i] == 2)
            {
                swap(A[i], A[two_index]);
                --two_index;
            }
            else
                ++i;
        }
    }
};
