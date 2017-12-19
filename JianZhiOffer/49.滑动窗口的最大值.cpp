/********************************************************************************
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 
解题思路:
1.使用双端队列，队列中的头节点保存的数据比后面的要大。
2.当前数据比队尾的数字大，说明当前这个数字在从现在起到后面的过程中可能是最大值，
  而之前队尾的数字不可能最大了，所以要删除队尾元素。
3.判断队头的元素是否超过size长度，超过的话移除队首坐标
*********************************************************************************/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> maxInWindows;
        if(num.size() < size || size < 1)
            return maxInWindows;
        deque<int> index;  //存放可能是最大值的那些数的索引
         //处理前size个数据
        //假如当前的元素比队列队尾的元素大，说明之前加入的这些元素不可能是最大值了。
        for(unsigned int i = 0; i < size; ++i)
        {
            while(index.size() != 0 && num[i] >= num[index.back()]) 
                index.pop_back(); //弹出比当前小的元素下标
            index.push_back(i); //队尾压入当前下标
        }
        //处理size往后的元素，这时候需要存储滑动窗口的最大值
        for(unsigned int i = size; i < num.size(); ++i)
        {
            maxInWindows.push_back(num[index.front()]);
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            if(!index.empty() && (i - index.front() + 1) > size)  //队首元素不在窗口内，移除队首元素
                index.pop_front();
            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);//最后还要压入一次
        return maxInWindows;
    }
};