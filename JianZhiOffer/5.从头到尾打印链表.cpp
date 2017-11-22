题目：输入一个链表，从尾到头打印链表每个节点的值。
解题思路：从头到尾访问链表，每访问一个存入栈中。最后链表的尾在栈顶，实现从尾到头打印。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ListValue;
        stack<int> ReverseList;
        while(head != NULL)
        {
            ReverseList.push(head->val);
            head = head->next;
        }
       while(!ReverseList.empty())
       {
           ListValue.push_back(ReverseList.top());
           ReverseList.pop();
       }   
        return ListValue;
    }
};