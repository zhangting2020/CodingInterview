/*
题目描述
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Follow up:
Can you solve it without using extra space?
题目解读：
给定一个链表，返回环开始的位置，如果没有环，则返回NULL。
解题思路：
https://www.cnblogs.com/fankongkong/p/7007869.html
1.首先用快慢指针判断有没有环，快指针一步走2个长度，慢指针1个长度，如果没有环直接返回NULL。
2.否则，先让两个指针相遇，此时快指针多走的距离肯定是环长度的倍数。让慢指针停留在相遇点，快指针指向
  链表表头；然后快慢指针同样的速度走，直到相遇即为环的入口。
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;  //只有一个结点不构成环
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                fast = head;
                while(fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;   
    }
};