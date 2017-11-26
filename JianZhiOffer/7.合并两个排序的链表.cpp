/****************************************************************************************
题目描述:输入两个单调递增的链表，输出两个链表合成后的链表，合成后的链表满足单调不减规则。
解题思路：使用非递归的方法，构造一个新的链表，每次把两个链表中的最小的数加入新链表的下一个位置。
注意：特殊输入判断：当有一个为空时，返回另一个的头。
      构造的新的链表的头要存放起来作为最后的返回值。
	  每次操作记得更新指针的位置
*****************************************************************************************\

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode* pMergeHead = NULL;
        ListNode* pMerge = NULL;
        //存储合并后的链表头
        if(pHead1->val <= pHead2->val)
        {
            pMergeHead = pHead1;
            pHead1 = pHead1->next;
            pMerge = pMergeHead;
        }
        else
        {
            pMergeHead = pHead2;
            pHead2 = pHead2->next;
            pMerge = pMergeHead;
        }

        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1->val <= pHead2->val)
            {
                pMerge->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                pMerge->next = pHead2;
                pHead2 = pHead2->next;
            }
            pMerge = pMerge->next;
        }
        while(pHead1 != NULL)
        {
            pMerge->next = pHead1;
            pMerge = pMerge->next;
            pHead1 = pHead1->next;
        }
            
        while(pHead2 != NULL)
        {
            pMerge->next = pHead2;
            pMerge = pMerge->next;
            pHead2 = pHead2->next;
        }
        return pMergeHead;    
        
    }
};