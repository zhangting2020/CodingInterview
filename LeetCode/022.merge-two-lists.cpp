/*
题目描述
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes 
of the first two lists.
题目解读：
合并两个有序的链表并且返回一个新链表。新链表应该通过拼接节点完成。
解题思路：
1.首先如果任何一个链表为空，应该返回另一个链表。
2.两个链表都不为空时，先找到链表头，因为最后要返回头结点。
3.按照两个链表的值调整指针合并链表
*/
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* preNode;
        ListNode* newhead = NULL;
        if(l1->val < l2->val)
        {
            preNode = l1;
            l1 = l1->next;
        }
        else
        {
            preNode = l2;
            l2 = l2->next;
        }
        newhead = preNode;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                preNode->next = l1;
                l1 = l1->next;
            }
            else
            {
                preNode->next = l2;
                l2 = l2->next;
            }
            preNode = preNode->next;
        }
        if(l1)
            preNode->next = l1;
        if(l2)
            preNode->next = l2;
        
        return newhead;
    }
};