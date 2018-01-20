/*****************************************************************************************************************************
题目描述
输入两个链表，找出它们的第一个公共结点。
解题思路：找到长短链表之间的长度差 diff,使长链表先走diff步；然后长短链表一起走，直到结点相同
*****************************************************************************************************************************/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL)
            return NULL;
        //获取链表长度
        int length1 = getLength(pHead1);
        int length2 = getLength(pHead2);
        //获取长度差，确定长短链表是哪一个
        ListNode* pNodeLong = pHead1;
        ListNode* pNodeShort = pHead2;
        int diff = length1 - length2;
        if(diff < 0)
        {
            pNodeLong = pHead2;
            pNodeShort = pHead1;
        }
        //长链表先走diff步
        while(diff--)
        {
            pNodeLong = pNodeLong->next;
        }
        //找第一个公共结点
        while(pNodeLong != NULL && pNodeShort != NULL && pNodeLong != pNodeShort)
        {
            pNodeLong = pNodeLong->next;
            pNodeShort = pNodeShort->next;
        }
        ListNode* firstCommonNode = pNodeLong;
        return firstCommonNode;
        
    }
    
    int getLength(ListNode* pHead)
    {
        int length = 0;
        while(pHead != NULL)
        {
            ++length;
            pHead = pHead->next;
        }
        return length;
    }
};

