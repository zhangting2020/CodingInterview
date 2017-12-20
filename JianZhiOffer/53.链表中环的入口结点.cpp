/********************************************************************************
题目描述
一个链表中包含环，请找出该链表的环的入口结点。
解题思路：快慢指针法：快指针走2步，慢指针走一步，相遇点在环中，此时快指针走的步数为
2x,慢指针为x，快指针比慢指针多走的长度就是环的长度n = x。
1.快慢指针，先在环中相遇，此时快指针多走的步数等于慢指针走的步数
2.让慢指针停留在相遇点，快指针指向链表表头；然后快慢指针同样的速度走，直到相遇即为环的入口。
注意：当链表只有一个结点时，不构成环
********************************************************************************/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL)
            return NULL;
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        while(p1 != NULL && p2 != NULL)   
        {
            p1 = p1->next;
            p2 = p2->next->next;  //快慢指针先在环中相遇
            if(p1 == p2)
            {
                p2 = pHead;   //快指针指向链表头
                while(p1 != p2)      //同速前进，相遇点即为环的入口
                {
                    p1 = p1->next;
            		p2 = p2->next;
                }
                return p1;//环的入口
            }
        }
        return NULL;  
    }
};