/*
题目描述
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3
题目解读：
给定二叉树，判断是否是对称的。
解题思路：
按照根左右的顺序访问左子树，按照根右左的顺序访问右子树，判断是否相等。
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        deque<TreeNode*> Nodes;
        if(root->left == NULL || root->right == NULL)
            return root->left == root->right; //当且仅当两个都为NULL时返回真
        Nodes.push_back(root->left);
        Nodes.push_back(root->right);
        
        while(!Nodes.empty())
        {
            TreeNode *LeftNode = Nodes.front();
            Nodes.pop_front();
            TreeNode *RightNode = Nodes.front();
            Nodes.pop_front();
            if( (LeftNode && RightNode == NULL) || (LeftNode == NULL && RightNode) )
                return false;
            if(LeftNode == NULL && RightNode == NULL)
                continue;
            if(LeftNode->val != RightNode->val)
                return false;
            Nodes.push_back(LeftNode->left);
            Nodes.push_back(RightNode->right);
            Nodes.push_back(LeftNode->right);
            Nodes.push_back(RightNode->left);
        }
        return true;
    }
};