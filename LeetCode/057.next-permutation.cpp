/*
题目描述
Implement next permutation, which rearranges numbers into the lexicographically next greater 
permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order 
(ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the 
right-hand column.
1,2,3→1,3,2
3,2,1→1,2,3
实现“下一个排列”函数，将排列中的数字重新排
1,1,5→1,5,1
题目解读：列成字典序中的下一个更大的排列。 如果这样的重新排列是不可能
的，它必须重新排列为可能的最低顺序（即升序排序）。
解题思路：
1 5 8 4 7 6 5 3 1，从右向左扫描，
1.如果左边的数比右边的数大，即高位比低位大，例如3 1说明这部分无论怎么交换都得不到更大的数，继续向左
2.遇到第一个左边比右边的数小的位置4 7，说明只要把比4大的数字放在4这个位置即可。为了得到最小的一个
比4 7 6 5 3 1大的数字，要找到4右边序列中刚好比4大的数，即5，交换得到5 7 6 4 3 1，然后5右边的数全部翻转
即可得到最小的一个排列。5 1 3 4 6 7。
*/
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        vector<int>::iterator i = num.end() - 2; //指向最后一个数字
        while( i >= num.begin() && ( *i >= *(i + 1) ) ) //从右开始，找到那个比自己右边的数小的位置
            --i; 
        if(i >= num.begin())  
        {
            vector<int>::iterator j = i + 1;  //从这个小的数右边开始
            while(j != num.end() && *j > *i)  
                ++j;
            swap(*i, *(--j));  //j指向要交换的那个数的右边，因此要减1
        }
        reverse(i + 1, num.end());
    }
};