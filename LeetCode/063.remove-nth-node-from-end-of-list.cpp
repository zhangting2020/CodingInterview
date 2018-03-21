/*
题目描述
Given a linked list, remove the n th node from the end of list and return its head.
For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note: 
Given n will always be valid.
Try to do this in one pass.
题目解读：
给定一个链表，从链表的末尾移除第n个结点，并且返回头结点。
解题思路：
增加一个额外结点，会使逻辑简单很多。使用两个指针，p1,p2，p1先走k步，然后同时走。
当p1到达末尾时，p2指向的位置恰好就是倒数第k+1个结点。因此p2的下一个位置就是倒数第k个结点。
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p1, *p2;
        ListNode *temp = new ListNode(0);  //增加一个额外结点
        temp->next = head;
        p1 = p2 = temp;
        while(n--)
            p1 = p1->next;  //p1先走k步
        while(p1->next)  //避免走到NULL位置
        {
            p1 = p1->next;
            p2 = p2->next; 
        }
        p2->next = p2->next->next;  //p2指向被删除的结点的前一个
        return temp->next;
    }
};