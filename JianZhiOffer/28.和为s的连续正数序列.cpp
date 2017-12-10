/**********************************************************************************************
题目描述:找出所有和为S的连续正数序列。例如9， [2 3 4] [4 5]
解题思路:设置两个值，分别表示序列中最大和最小的数 small 和 big; mid 表示small最大可以走到的位置；
         sequence存放满足要求的一个序列
         1. 如果当前的和满足要求，则将 small-big 之间的数存入sequence，并保存结果
		 2. 如果当前的和小于要求的数， 则说明应该加入一个更大的数，因此增加big
		 3. 如果当前的和大于要求的数，则说明应该减少一个数，因此增加small，相当于去掉了一个最小的数
注意：sum的值不能小于3，因为序列至少有两个正数1和2
      sequence每次保存了一个满足要求的序列，当将sequence存入result时，一定要清空sequence，为存入新的序列做准备
	  在更新序列中最大和最小的数big，small时，记得同时更新cursum。

***********************************************************************************************/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if(sum < 3)
            return result;
        vector<int> sequence;
        int small = 1;
        int big = 2;   //初始化序列中最小和最大值为1和2
        int mid = sum / 2;  //设置small最大可以到达的数
        int cursum = small + big;
        while(small <= mid)
        {
            if(cursum == sum)    //当前和满足
            {
               for(int i = small; i <= big; ++i)
               {
                   sequence.push_back(i);   //把当前的序列保存下来
               }
                result.push_back(sequence);
                sequence.clear();
                ++big;
                cursum += big;
            }
            if(cursum < sum)
            {
                ++big;   //加入一个数
                cursum += big;
            }
                
            if(cursum > sum)
            {
                cursum -= small;
                ++small; //减少一个数
            }
                
        }
        return result;
    }
};