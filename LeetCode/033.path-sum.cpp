/*
题目描述
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all 
the values along the path equals the given sum.
For example:
Given the below binary tree andsum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path5->4->11->2which sum is 22.
题目解读：
给定一个二叉树和一个数值sum，判断二叉树从根->叶节点是否存在一条路径，该路径上的数和为sum。
解题思路：
递归求解。当根节点为空时直接返回false；当当前结点为叶节点，且和为sum，返回true；
否则在左右子树中寻找下一条路径。
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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL && sum - root->val == 0)
            return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
    
    
};