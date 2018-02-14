/*
题目描述
Given a sorted linked list, delete all duplicates such that each 
element appear only once.
For example,
Given1->1->2, return1->2.
Given1->1->2->3->3, return1->2->3.
题目解读：
给定一个排序链表，删除所有重复元素，使每个元素都只出现一次。
解题思路：
curNode:当前节点；nextNode:下一个节点
1.每次比较当前节点和下一个节点，若相等，则将当前节点连到相同节点的下
一个节点。
2.若不相等，则当前节点后移一个。nextNode需要根据curNode及curNode的下
一个节点的状态设置。
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *curNode = head;
        ListNode *nextNode = head->next;
        while(nextNode)
        {
            if(curNode->val == nextNode->val)
            {
                curNode->next = nextNode->next;  //连接到重复元素的下一个
                nextNode = curNode->next;
            }
            else
            {
                curNode = curNode->next;
                if(curNode != NULL && curNode->next != NULL)
                    nextNode = curNode->next;
                else
                    nextNode = NULL;
            }
           
        }
        return head;
        
    }
};