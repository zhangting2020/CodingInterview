/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
/*
思路：
1.preNode：当前结点的前一个结点，pNode当前结点，pNext当前结点的下一个结点
2.遍历整个链表。
  如果 pNext!=NULl，并且*pNode=*pNext,则有重复的值，置删除标志位 bDelete = true
3.if: bDelete != true,无重复结点，则 preNode = pNode, pNode = pNode->next,指针后移这一轮循环结束
  else: bDelete = true,有重复结点，则删除重复结点
        在删除重复结点后，需要注意：
        若前面的结点全部被删除了，此时preNode = NULL,需要将头结点指向当前的头结点
        若前面还有结点，preNode != NULL, 需要将preNode与删除的结点后面的链表连接
  这一轮循环结束
  

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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL)
            return pHead;
         
        ListNode *preNode = NULL;
        ListNode *pNode = pHead;
        ListNode *pNext;
        
        while(pNode != NULL)
        {
            bool bDelete = false;
            pNext = pNode->next;
            if(pNext != NULL && pNode->val == pNext->val)
                bDelete = true;
            
            if(!bDelete)
            {
                preNode = pNode;
                pNode = pNode->next;
            }
            else
            {
                int value = pNode->val;
                ListNode *pTobeDelete = pNode;
                while(pTobeDelete != NULL &&  pTobeDelete->val == value)
                {
                    pNext = pTobeDelete->next;
                    delete pTobeDelete;
                    pTobeDelete = NULL;
                    pTobeDelete = pNext;
                }
                
                if(preNode == NULL)
                    pHead = pNext;
                else
                    preNode->next = pNext;
                
                pNode = pNext;
            }

}
        return pHead;

    }
};