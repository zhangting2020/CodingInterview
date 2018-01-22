/****************************************************************************
��Ŀ����
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?
��Ŀ������ж������Ƿ��л�
����˼·��
����ָ�롣��Ҫע�����������ʱ�ϲ��Ϸ�
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