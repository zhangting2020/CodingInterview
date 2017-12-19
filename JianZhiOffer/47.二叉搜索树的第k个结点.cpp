/********************************************************************************
题目描述
给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，
按结点数值大小顺序第三个结点的值为4。
解题思路：
由于二叉搜索树的特点，左子树小于根，右子树大于根，按照中序遍历的顺序可得到一个由小
到大的序列
*********************************************************************************/
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k <= 0)
            return NULL;
        return KthNodeCore(pRoot, k);
    }
    
    TreeNode* KthNodeCore(TreeNode* pRoot, int& k)
    {
        TreeNode* result = NULL;
        if(pRoot->left != NULL)
            result = KthNodeCore(pRoot->left, k);  //中序遍历，一直走到最左的子节点。
        if(result == NULL)
        {
            if(k == 1)
                result = pRoot;
            --k;
        }
        if(result == NULL && pRoot->right != NULL)
            result = KthNodeCore(pRoot->right, k);
        return result;
    }

    
};