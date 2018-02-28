/********************************************************************
题目描述
Given a sorted array and a target value, return the index if the target 
is found. If not, return the index where it would be if it were inserted 
in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
题目解读：
给定一个排序数组和一个目标值。如果数组中有该值，则返回它在数组中的索引；
入如果数组中没有，则返回它按顺序插入数组后的索引。
解题思路：
二分查找法。
********************************************************************/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0;
        int high = n - 1;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};