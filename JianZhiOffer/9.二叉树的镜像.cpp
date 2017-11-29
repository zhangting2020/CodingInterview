/**************************************************************
题目描述：操作给定的二叉树，将其变换为源二叉树的镜像。
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
解题思路：使用非递归的方法。用一个容器，这里选择的栈来保存树中的结点。
当前结点有左孩子时，先将左孩子放入临时的结点temp;
交换左右孩子，完成当前结点孩子的镜像；
将当前结点的左右孩子入栈（注意入栈前一定要判断左右孩子是否为空，否则会出现栈溢出，越界的错误）
进行下次循环
***************************************************************/

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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return;
        TreeNode* pNode;
        stack<TreeNode*> nodes;
        nodes.push(pRoot);
        while(!nodes.empty())
        {
            pNode = nodes.top();
            nodes.pop();
            TreeNode* temp = NULL;
            if(pNode->left != NULL)
            {
                temp = pNode->left;
            }
            pNode->left = pNode->right;
            if(pNode->left != NULL)
                nodes.push(pNode->left);
            pNode->right = temp;
            if(pNode->right != NULL)
            {
                nodes.push(pNode->right);
            }
        }
    }
};