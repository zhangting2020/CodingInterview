/********************************************************************************
题目描述
输入一个链表，反转链表后，输出链表的所有元素。
解题思路：遍历链表，调整指针方向
1.定义当前结点的前一个结点pPre,和后一个结点pNext
2.每次调整前，先保存当前结点后的结点到pNext，然后调整指针使当前结点的下一个为pPre
3.指针后移，继续调整。
********************************************************************************/

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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL)
            return NULL;
        ListNode* ReverseHead = NULL;
        ListNode* pNode = pHead;
        ListNode* pNext;
        ListNode* pPre = NULL;
        while(pNode != NULL)
        {
            if(pNode->next == NULL)
                ReverseHead = pNode;
            pNext = pNode->next;  //先保存链表中当前结点后的结点
            pNode->next = pPre;  //当前结点指向前一个结点
            pPre = pNode;   //指针后移
            pNode = pNext;
        }
        return ReverseHead;

    }
};