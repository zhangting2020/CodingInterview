/*
题目描述
A linked list is given such that each node contains an additional random pointer which could point to 
any node in the list or null.
Return a deep copy of the list.
题目描述：
给定一个链表，每一个结点都包含了一个额外的随机的指针，指向链表中任意结点或者NULL。复制该链表
解题思路：
1.首先复制每一个结点，原始结点为N，则复制后的结点为N'。将N'连接在N的后面。得到一个链表：
  A->A'->B->B'->C->C'->D->D'
2.从头访问链表，每访问一个原始结点，就可以知道它的额外指针指向的地址，比如A的额外指针指向的是C，
  那么通过访问A，知道A'的额外指针应该指向的是A的额外指针所指向的位置（C）的下一个位置C'。
3.分离两个链表
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode* curNode = head;
        //复制链表，并将复制的结点连接在对应的原始结点的后面
        while (curNode) {
            RandomListNode* Copy = new RandomListNode(curNode->label);
            Copy->next = curNode->next;
            curNode->next = Copy;
            curNode = Copy->next;
        }
        //安排随机指针的指向
        RandomListNode* OriginNode = head;
        while (OriginNode) {
            if (OriginNode->random)
                OriginNode->next->random = OriginNode->random->next;
            OriginNode = OriginNode->next->next; 
        }
        //分离两个链表
        RandomListNode* pCloneHead = head->next; //保存新链表头结点
        OriginNode = head;
        while (OriginNode) {
            RandomListNode* clone = OriginNode->next;
            OriginNode->next = clone->next;
            if (clone->next) {
                clone->next = clone->next->next;
                OriginNode = OriginNode->next;
            }
            else
                break;
        }
        return pCloneHead;
    }
};