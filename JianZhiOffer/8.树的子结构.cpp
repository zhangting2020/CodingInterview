/*****************************************************************
题目描述:输入两棵二叉树A，B，判断B是不是A的子结构。（ps：约定空树不是任意一个树的子结构）
解题思路：递归地判断树B的结点是不是在树A中。
           HasSubtree作为算法的主要函数：根据题目要求，当有一个为空，那么就无子结构。
		   所以二者都不为空时，如果根节点相等，那么判断这个根节点的子树有没有子结构
		   否则分别判断左右子树有没有子结构
		   Tree1HasTree2用来递归地判断子树中是否有子结构。当首次进入这个函数时，两个根节点满足相等。
		   当pRoot2为NULl时，说明已经判断完当前的子树的所有结点，说明满足都相等，返回true;
		   当Proot1为NULL时，由于PRoot2不为NULL（否则已经返回了），因此不满足；
		   当两个根节点的值不相等时（第二次及以后的递归会发生），不满足；
		   否则继续看当前根节点的左子树和右子树是否满足条件。
******************************************************************/

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1 != NULL && pRoot2 != NULL)
        {
            if(pRoot1->val == pRoot2->val)
                result = Tree1HasTree2(pRoot1, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        
        return result;

    }
    
    bool Tree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return Tree1HasTree2(pRoot1->left,pRoot2->left) && Tree1HasTree2(pRoot1->right, pRoot2->right);

    }
};