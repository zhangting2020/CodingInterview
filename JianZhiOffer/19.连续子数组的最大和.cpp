/**************************************************************************
题目描述:计算连续子向量的最大和。例如:{6,-3,-2,7,-15,1,2,2},
连续子向量的最大和为8(从第0个开始,到第3个为止)
解题思路：current 记录当前累加和， maxsum记录最大和。
          如果current不是整正数，则丢弃掉这个和，因为它对增大和没有贡献。因此：
		  1. current <= 0，则更新current为下一个要加的数字
		  2. current > 0，则使current加上下一个要加的数字
		  3. 若 current > maxsum，则maxsum = current;
***************************************************************************/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        vector<int>::iterator it = array.begin();
        int maxsum = *it;  //最大和先初始化为数组第一个元素，因为至少有一个数
        int current = 0;
        for(it; it != array.end(); ++it)
        {
            if(current <= 0)
                current = *it;   //当前和为负值，抛弃当前和，重新找最大和
            else
                current += *it;  //当前和为整数，继续累加
            
            if(maxsum < current)
                maxsum = current;
        }
        
        return maxsum;
    
    }
};