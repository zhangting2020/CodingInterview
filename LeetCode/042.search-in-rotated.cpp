
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
1.若left < target,则在left~mid中查找
2.若right > target，则在mid~right中查找。
注意：由于可以出现重复数字，333333012333，为了过滤掉重复元素，mid=left或者mid=right时，调整指针。
