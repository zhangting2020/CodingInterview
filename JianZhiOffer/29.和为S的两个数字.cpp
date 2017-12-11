/***************************************************************************************************
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，
输出两个数的乘积最小的。
输出描述:对应每个测试案例，输出两个数，小的先输出。

解题思路：使用双指针一个指向数组开头，一个指向数组末尾，循环地判断当前和是否满足要求。
1.初始化两个指针small和big分别指向数组开头和末尾；初始化当前和为这两个位置的数相加；初始化最小的乘积
2.如果当前和小于要求，则small指向下一个数
3.如果当前和大于要求，则big指向前一个数
4.如果当前和满足要求，则判断当前积是否更小。是则更新最小积和结果 
*****************************************************************************************************/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.empty())
            return result;
        //定义两个指针，指向array的第一个和最后一个位置
        int small = 0;
        int big = array.size() - 1;
        int cursum = array[small] + array[big]; 
        int product = array[small] * array[big]; ;  //记录当前的积
        int minprod = 0x7fffffff;
        
        while(small < big)
        {
            if(cursum == sum)
            {
                if(product < minprod)
                {
                    result.clear();
                    result.push_back(array[small]);
                    result.push_back(array[big]);
                    minprod = product;
                }
                --big;
                ++small;
            }
            if(cursum < sum)
                ++small;
            if(cursum > sum)
                --big;
            //更新当前的和与积
            cursum = array[small] + array[big];
            product = array[small] * array[big];
        }
        return result;
    }
};