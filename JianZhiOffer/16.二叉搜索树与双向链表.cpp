/*******************************************************************************
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，
只能调整树中结点指针的指向。
                    10
		       6           14
		   4      8    12       16
解题思路：最终要形成的双向链表为 4 6 8 10 12 14 16，之间有双向的连接
          1. 首先找到左子树的中序遍历尾结点 pLastNodeInList
		  2. 将 pcurrent 的左指针指向 pLastNodeInList, pLastNodeInList 右指针指向pcurrent
		  3. 将当前中序的尾结点 pLastNodeInList 指向pcurrent
		  4. 递归地处理右子树
注意: 最后要返回的是链表头结点，因此需要从尾结点开始向左找到链表头
**********************************************************************************/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        TreeNode* pLastNodeInList = NULL;
        ConvertNode(pRootOfTree, &pLastNodeInList);
        //需要返回双向链表头结点，因此从尾遍历到头
        TreeNode* pHead = pLastNodeInList;
        while(pHead != NULL && pHead->left != NULL)
            pHead = pHead->left;
        return pHead;
        
    }
    
    
    void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList)
    {
        if(pNode == NULL)
            return;
        TreeNode* pcurrent = pNode;
        if(pcurrent->left != NULL)
            ConvertNode(pcurrent->left, pLastNodeInList);
        pcurrent->left = *pLastNodeInList;   //根节点指向中序遍历的尾结点
        if(*pLastNodeInList != NULL)
            (*pLastNodeInList)->right = pcurrent;  //中序遍历的尾结点指向根节点上
        *pLastNodeInList = pcurrent;
        if(pcurrent->right != NULL)
            ConvertNode(pcurrent->right, pLastNodeInList);

    }
};