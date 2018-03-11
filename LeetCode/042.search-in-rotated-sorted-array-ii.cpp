/*
题目描述
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
题目解读：
给定一个旋转后的排序数组，判断给定的目标是否在数组中。可能会有重复的数值。
解题思路：
left,mid,right三个指针，
1.若mid == target，则返回真
2.若left=mid=right,无法决定在哪一半查找，因此left++,right--;
  否则，若left < mid,则左边有序，在left~mid中查找
  否则，若mid <= right，则右边有序，在mid~right中查找。
注意：由于可以出现重复数字，333333012333，为了过滤掉重复元素，mid=left或者mid=right时，调整指针。
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(A[mid] == target)
                return true;
            if(A[left] == A[mid] && A[mid] == A[right]) //左右两边有重复元素，缩小范围
            {
                left++;
                right--;
            }
            else if(A[mid] >= A[left]) //左边有序
            {
                if(A[mid] > target && A[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(A[mid] <= A[right]) //左边有序
            {
                if(A[mid] < target && A[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};