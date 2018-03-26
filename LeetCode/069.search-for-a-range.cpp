/*
题目描述
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return[-1, -1].
For example,
Given[5, 7, 7, 8, 8, 10]and target value 8,
return[3, 4].
题目解读：
给定一个排序数组，找到目标值开始和结束的位置。如果没有找到，则返回[-1, -1]。
解题思路：
利用二分法，时间复杂度为O(logN)。
1.找到目标值时，在目标值左边继续搜索。因此当中间位置的值 >= 目标值时，在左半边搜索
2.得到开始的位置后，在右半边折半查找结束位置。
*/
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        if (n <= 0) return res;
        int start = SearchRangeCore(A, 0, n-1, target, true);
        if (start == n || A[start] != target)
            return res;
        res[0] = start;
        res[1] = SearchRangeCore(A, start, n-1, target, false) - 1;
        return res;
    }
    
    int SearchRangeCore(int A[], int begin, int ending, int target, bool left) {
        int low = begin, high = ending;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (A[mid] > target || (left && target == A[mid]))
                high = mid-1;
            else
                low = mid + 1;
        }
        return low;
    }
};