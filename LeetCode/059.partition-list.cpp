/*
题目描述
Given a linked list and a value x, partition it such that all nodes less than x come before 
nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2and x = 3,
return 1->2->2->4->3->5.
题目解读：
给定一个链表和一个值，将链表分开，所有比x小的结点在左边。
解题思路：
设置两个额外的结点，作为小结点部分的头和大结点部分的头。分别将结点添加到对应的链表中。
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
    ListNode *partition(ListNode *head, int x) {
        ListNode *pHead1 = new ListNode(0);
        ListNode *pHead2 = new ListNode(0);
        ListNode *cur1 = pHead1, *cur2 = pHead2;
        while(head)
        {
            if(head->val < x)
            {
                cur1->next = head;
                cur1 = cur1->next;
            }
            else
            {
                cur2->next = head;
                cur2 = cur2->next;
            }
            head = head->next;
        }
        cur1->next = pHead2->next;  //拼接两部分链表
        cur2->next = NULL;//重要，因为最后链表2的最后一个结点并没有指向NULL
        return pHead1->next;
    }
};
