/****************************************************************************
题目描述
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
题目解读：判断链表是否有环
解题思路：
快慢指针。需要注意链表结点访问时合不合法
*****************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* pNode1 = head;
        ListNode* pNode2 = head;
        while(pNode1->next != NULL && pNode2->next != NULL && pNode2->next->next != NULL)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next->next;
            if(pNode1 == pNode2)
                return true;
        }
        return false;
    }
};