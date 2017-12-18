/***************************************************************************************************
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
解题思路：
                a
        b                 c
    d        e          f    g
	       h    i
中序遍历的顺序是：左子结点，父节点，右子节点；
1.当一个结点有右子树时，那么它的下一个结点应该是右子树的最左结点
2.当一个结点没有右子树时，分两种情况：  
  如果这个结点是左子节点，那么下一个结点就是它的父节点
  如果这个结点不是左子节点，例如i,那么下一个结点要返回父节点找，一直找到某一个结点，它是左子节点，
  该左子结点的父节点就是下一个结点。
****************************************************************************************************/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL)
            return pNode;
        TreeLinkNode* nextNode;
        if(pNode->right != NULL)  //若有右子树
        {
            pNode = pNode->right;
            while(pNode->left)
            {
                pNode = pNode->left;  //沿着右子树找最左的子节点
            }
            nextNode = pNode;
        }
        else  //pNode没有右子树
        {
            while(pNode->next != NULL)  //当存在父节点，即不是根节点
            {
                if(pNode->next->left != pNode)//当前结点不是其父节点的左子节点
                    pNode = pNode->next; //向上寻找
                else
                    break;
            }
            nextNode = pNode->next; //返回父节点
        }
        return nextNode;
        
    }
};