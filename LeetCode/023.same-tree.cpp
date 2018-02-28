/*
题目描述
Given two binary trees, write a function to check if they are equal 
or not.
Two binary trees are considered equal if they are structurally 
identical and the nodes have the same value.
题目解读：
给定两个二叉树，判断他们是否相等。结构和节点值一样。
解题思路：
递归地求解。
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        if(p->val == q->val)
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return false;
    }
};