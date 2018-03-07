/*
题目描述
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, 
only nodes itself can be changed.
题目解读：
给定一个链表，交换每两个相邻结点，并返回链表头。只能使用连续内存空间，不可修改链表的值。
解题思路：
增加一个新的链表头为 newhead，目的是为了不单独处理前两个结点。
preNode:已经处理过的最后一个结点；curNode：相邻结点的第一个；nextNode：相邻结点的第二个。
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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *newHead = new ListNode(0); //增加一个额外的结点
		ListNode *preNode = newHead, *curNode = head, *nextNode = head->next; 
        while(curNode)
        {
            if(curNode->next != NULL)
                nextNode = curNode->next;
            else
                break;
        
            curNode->next = nextNode->next; //交换结点
            nextNode->next = curNode;
            preNode->next = nextNode;
            
            preNode = curNode; //上次交换后，末尾结点是curNode
            if(preNode->next != NULL)
                curNode = preNode->next;
        }
		newHead = newHead->next;
        return newHead;
    }
};
   
   