/*
题目描述
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A =[2,3,1,1,4], return true.
A =[3,2,1,0,4], return false.
题目解读：
给定一个非负整数数组，最开始在第一个位置，数组中每一个元素代表你在那个位置可以跳跃的最大的长度。
判断你是否可以到达最后一个索引。
解题思路：
从右至左地区访问数组，lastpos为最左的一个好位置（从这个好位置出发一定能到达最后），初始化lastpos为
最后一个位置（末尾位置一定是好位置），假设当前访问的位置为i：
1.若i+A[i]>=lastpos，说明从当前位置出发，跳跃一定能到达最后一个；故lastpos=i，向左继续检查
2.若i+A[i]<lastpos，说明从此位置出发，跳跃任何步数都无法到达lastpos，意味着到达不了末尾；向左检查。
3.如果最终lastpos=0，则说明从第一个位置出发，一定能到达末尾。
*/
class Solution {
public:
    bool canJump(int A[], int n) {
        int lastpos = n - 1;
        for(int i = n - 1; i >= 0; --i)
        {
            if(i + A[i] >= lastpos)
                lastpos = i;
        }
        return lastpos == 0;
    }
};