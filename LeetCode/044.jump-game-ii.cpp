
题目描述
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A =[2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump1 step from index 0 to 1, then 3 steps 
to the last index.)
题目解读：
给定一个包含非负整数的数组，最开始在第一个位置，数组中每一个元素代表你可以跳跃的最大距离。
目标是跳跃最少的步数，到达最后一个位置。
解题思路：
从右至左的访问数组，计算从当前位置出发最少还需要跳跃多少步才能到达数组末尾。lastpos之前的跳跃中，需要
最少步数的位置。step数组存放每一个位置需要跳跃的最少步数。算法思路如下：
  若 i + A[i] >= n - 1，说明从当前位置一步可到数组末尾，则step[i] = 1;否则：
  若 i + A[i] >= lastpos，说明一步到达上一次最少步数的位置，则step[i] = step[lastpos] + 1;否则：
  int minJump = n;
  for j = A[i] : 1   从当前位置逐步走j，找最小跳跃数
	若 step[i + j] + 1 < minJump，则minJump = step[i + j] + 1
  step[i] = minJump
  