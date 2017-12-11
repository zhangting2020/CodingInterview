/**********************************************************************************************
题目描述:扑克牌顺子
解题思路：1.对数组由小到大排序
          2.统计0的个数，以及需要插入0的个数，若0的个数大于等于需求，则构成顺子
注意：如果有相同的牌，即对子，则不构成顺子
      如果牌的个数小于3无法构成顺子
************************************************************************************************/

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size() < 3)
            return false;   //牌少于3张无法构成顺子
        qsort(&numbers[0], numbers.size(), sizeof(int), compare);
        vector<int>::iterator it = numbers.begin();
        int zero = 0;
        int interval = 0;
        while( (it != numbers.end()) && (*it == 0) )    //统计数组中0的个数
        {
            ++zero;
            ++it;
        }
        while(it != numbers.end())
        {
            if((it + 1) != numbers.end())  //it的下一个位置存在
            {
                if(*it == *(it + 1))   //若存在对子
                    return false;
                interval += *(it + 1) - *it - 1;  //计算两个数之间要插入的间隔，比如2,3， 3-2-1=0
            }
            ++it;
        }
        
        if(interval > zero)  //若要填补的空缺比0大
            return false;
        else
            return true;
    }
    
    static int compare(const void *num1, const void *num2)
    {
        return *(int*)num1 - *(int*)num2;  //升序排序
    }
};