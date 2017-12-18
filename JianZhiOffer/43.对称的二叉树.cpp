/*********************************************************************************************************
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
解题思路：
前序遍历的顺序是：根，左子节点，右子节点；定义一种和前序遍历对称的访问顺序：根，右子节点，左子节点
**********************************************************************************************************/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymetrical(pRoot, pRoot);
    }
    bool isSymetrical(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL && pRoot2 == NULL)
            return true;
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return isSymetrical(pRoot1->left, pRoot2->right) && isSymetrical(pRoot1->right, pRoot2->left);
    }

};