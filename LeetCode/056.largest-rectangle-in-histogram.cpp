/*
题目描述
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height =[2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, which has area =10unit.
For example,
Given height =[2,1,5,6,2,3],
return10.
题目解读：
给定n个非负整数代表了直方图的高度，每一个bar的宽度为1，找到直方图中最大的矩形面积。比如[2,1,5,6,2,3],
最大的矩形面积是第三个和第四个条构成的矩形，面积为10。
解题思路：
把直方图中的每一个bar当做一块木板。用一个栈来保存下标（索引），遇到比栈中下标对应的值大的高度时，
就将这个这个高度的下标压入栈中，即保证栈中下标对应的高度是非降型的；遇到比栈中下标对应值小的高度，
就计算此时的面积，和res比较，取较大值。为了保证到最后时依旧存在一个不升状态，即结束状态，要在height
中压入一个0。在遇到比栈顶木板高度小的板子时，要停下来计算面积，是因为，之前的板子高度一直在递增，短板
出现时，意味着矩形的高度会出现变化。
可行的原因：保持栈内板子的高度非递减，当遇到比栈顶低的板子，就统计之前的高度。方法是：从栈顶的板子开始
向前逐个找起始板子，计算面积，由于向前的高度是递减的，所以面积计算公式：
栈顶的板子高度*板子总宽度。
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> index;  //存放高度索引
        height.push_back(0);
        int area = 0;
        for(int i = 0; i < height.size(); ++i)
        {
            if(index.empty() || height[index.top()] <= height[i])
                index.push(i);
            else
            {
                int temp = index.top();
                index.pop();
                int width = index.empty() ? i : (i - index.top() - 1);
                area = max(area, height[temp] * width);
                --i;
            }
        }
        return area;
    }
};