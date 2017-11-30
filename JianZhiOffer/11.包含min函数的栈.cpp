/***************************************************************************
题目描述：定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。

解题思路：使用两个栈。stack1用来作为主栈存储数据元素，stack2用来作为辅助栈，
          每次push一个值进stack1后，把当前最小的元素push进stack2
		  每次pop一个值时，把stack2也pop出一个元素。
****************************************************************************/

class Solution {
public:
    stack<int> stack1;
    stack<int> stack2;
    void push(int value) {
        stack1.push(value);
        if (stack2.empty() || value < stack2.top())
            stack2.push(value);
        else
            stack2.push(stack2.top());
    }
    
    void pop() {
        if(!stack1.empty() && !stack2.empty())
        {
            stack2.pop();
            stack1.pop();
        }
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
};