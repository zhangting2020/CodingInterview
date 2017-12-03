/****************************************************************
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

解题思路：1.将复制的结点附在原结点的后面
          2.遍历总的链表，给其中的random指针依次赋值
		  3.将总的链表分为两个子链表
*****************************************************************/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNode(pHead);
        ConnectRandomNode(pHead);
        return ConvertListNode(pHead);
        
    }
    
    void CloneNode(RandomListNode* pHead)
    {
        if (pHead == NULL)
            return;
        RandomListNode* pNode = pHead;
        while(pNode != NULL)
        {
            RandomListNode* pclone = new RandomListNode(pNode->label);    
            pclone->next = pNode->next; //将复制的结点连在原来的结点会面
            pNode->next = pclone;
            pNode = pclone->next;
        }
    }
    
    void ConnectRandomNode(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return;
        
        RandomListNode* pNode = pHead;
        RandomListNode* pclone = NULL;
        while(pNode != NULL)
        {
            pclone = pNode->next;
            if(pNode->random != NULL)   //将每一个复制后的结点的random指针赋值
                pclone->random = pNode->random->next;
            
            pNode = pclone->next;
        }
    }
    
    RandomListNode* ConvertListNode(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        RandomListNode* pNode = pHead;
        RandomListNode* pcloneHead = NULL;
        RandomListNode* pcloneNode = NULL;
        if(pNode != NULL)
        {
            pcloneHead = pcloneNode = pNode->next;
            pNode->next = pcloneNode->next;
            pNode = pNode->next;
        }
        while(pNode != NULL)                                //将链表拆分为两个
        {
            pcloneNode->next = pNode->next;
            pcloneNode = pcloneNode->next;
            pNode->next = pcloneNode->next;
            pNode = pNode->next;
            
        }
        return pcloneHead;
    }

};