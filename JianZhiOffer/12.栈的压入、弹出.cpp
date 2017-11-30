/************************************************************************************
题目描述：
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列。但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）

解题思路：popV出栈序列， pushV入栈序列，s1用来执行入栈出栈操作
          当前popV的元素如果在栈顶，直接将s1栈顶元素pop
		  当前元素如果不在栈顶，将还未入栈pushV的元素依次入栈，直到当前应该出栈的元素已经位于s1栈顶
		  

*************************************************************************************/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty() || popV.empty())
            return false;
        stack<int> s1;  //主栈
        vector<int>::iterator it1 = pushV.begin();
        vector<int>::iterator it2 = popV.begin();  //出栈元素指针
        bool result = false;
        for(it2; it2 != popV.end(); ++it2)  //遍历出栈序列，相应地对s1执行入栈，出栈操作，看s1最终能不能完成这样的顺序
        {
            //如果栈顶元素和要出栈的元素不相等,将没有入栈的元素依次入栈，直到遇到相等的元素
            while(s1.empty() || s1.top() != *it2 )
            {
                if(it1 == pushV.end())
                    break;
                else
                    s1.push(*it1);
                ++it1;
            }
                
			//由于先push过，因此当前栈顶元素要么就是要出栈的元素，要么出栈顺序就不对
            if(!s1.empty() && s1.top() == *it2)   //要出栈的元素与栈顶相等
            {
                s1.pop();
        	}

        }
        
        if(s1.empty())   //按照出栈入栈的序列，已经完成了匹配，s1栈空；否则即使出栈序列遍历完，s1不会pop空
            result = true;
        return result;
    }
};
