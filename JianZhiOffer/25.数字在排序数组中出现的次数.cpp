/**************************************************************************************************
题目描述
统计一个数字在排序数组中出现的次数。例如 1 2 3 3 3 3 4 5. 其中3出现的次数为4
解题思路：
方法一：由于是排序数组，可以二分法去查找中间的3。然后向前向后分别查第一个和最后一个3.但当整
个数组都是3时，复杂度就为 O(n).
方法二：充分利用二分法。先找到中间的3,然后二分地找第一个3和最后一个3.下面是找第一个3的流程
        1. 先找到第一个3的坐标 mid
		2. 若中间的数的前一个不为3,则第一个3就是 mid
		3. 若中间的数小于3,在后半段查找
		4. 若中间的数大于3,在前半段查找
注意：循环退出条件，以及当找到第一个或最后一个位置时，要退出循环
****************************************************************************************************/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        int first = -1, mid, last = -1;
        int start = 0;
        int end = data.size() - 1;
        //查找第一个k
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(data[mid] == k) 
            {
                if(data[mid - 1] != k) //如果中间的数是k,前一个不是k
                {
                    first = mid;   //第一个k
                    break;
                }
                else
                    end = mid - 1;
            }
            if(data[mid] < k)
                start = mid + 1;    //在后半段查找
            if(data[mid] > k)
                end = mid - 1;
        }
        
        //查找最后一个k
        start = 0;
        end = data.size() - 1;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(data[mid] == k)
            {
                if(data[mid + 1] != k)   //如果中间的数字是k而它的下一个不是k
                {
                    last = mid;
                    break;
                }
                else
                    start = mid + 1;
            }
            if(data[mid] < k)
                start = mid + 1;    //在后半段查找
            if(data[mid] > k)
                end = mid - 1;
                
        }
        int number = 0;
        if(first != -1 && last != -1)
            number = last - first + 1;
        return number;
        }
        
        

};