/*
题目描述
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e.,0 1 2 4 5 6 7might become4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
题目解读：
假设一个排序数组被旋转了，在其中查找目标值，并返回它的索引，没有目标值则返回-1。
解题思路：
1.使用left,right,mid三个指针，折半查找。
2.若mid = target，直接返回结果，否则
2.当left < mid，左半边有序：
  若left <= target,target < mid,则right = mid - 1;否则，left = mid + 1
3.若mid<right，则右半边有序：
  若mid < target，target <= right，则left = mid+1，否则，right = mid - 1。
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n <= 0)
            return -1;
        int left = 0, right = n - 1, mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(A[mid] == target)
                return mid;
            if(A[left] <= A[mid])
            {
                if(A[left] <= target && target < A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if(A[mid] < target && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
