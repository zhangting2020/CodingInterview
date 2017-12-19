/********************************************************************************
题目描述
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
解题思路：使用最大堆和最小堆。将数据平均分为两部分，左面是最大堆，右面是最小堆；
最大堆中的数全部小于最小堆的数
1.当当前数据个数为偶数个时，将数据插入到最小堆；当当前数据为奇数个时，插入到最大堆
2.当往最小堆插入数据时，首先要判断插入的数据是否比最大堆的最大值还小，若是，则违反规则，
需要把当前的值先插入到最大堆，然后调整最大堆得到最大堆中当前的最大值，将这个最大值插入
最小堆
3.往最大堆插入数据时同理
*********************************************************************************/
class Solution {
public:
    void Insert(int num)
    {
        if( ( (max.size() + min.size()) & 1 ) == 0 ) //目前共偶数个数，插入到最小堆
        {
            if(max.size() > 0 && num < max[0])  //要插入的数比最大堆的最大值大（保证最大堆的数都比最小堆小）
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0]; //获取新的最大堆的最大值
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        }
        else  //插入到最大堆
        {
            if(min.size() > 0 && num > min[0])   //要插入的数若比最小堆的最小值大（保证最大堆的数都比最小堆小）
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    { 
        int size = min.size() + max.size();
        double median = 0;
        if( (size & 1) == 0) //偶数个
            median = (max[0] + min[0]) / 2.0;
        else
            median = min[0];
        return median;
    
    }
private:
    vector<int> max;
    vector<int> min;

};