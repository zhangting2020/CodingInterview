/*
题目描述
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree andsum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
题目解读：
给定二叉树和一个目标值，找出所有从根-叶子结点的路径，使得路径和等于给定目标值。
解题思路：
深度优先搜索（DFS）。从根结点向叶子结点走，先搜索左子树，然后搜索右子树路径：
1.每次将当前结点加入路径
2.若当前结点为叶子结点且当前和满足要求，存储路径
3.否则，分别搜索左右子树，目标和sum使用sum-当前结点值
4.从当前路径移除最后加入的结点
所以，首先会一直走到叶子结点，然后加入符合要求的路径，否则会回退到上一步。
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        SearchPath(root, sum, path, res);
        return res;
    }
    
    void SearchPath(TreeNode* root, int sum, vector<int> &path, vector<vector<int> > &res) {
        if(root == NULL) 
            return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && sum - root->val == 0){
            res.push_back(path);
        } 
        SearchPath(root->left, sum - root->val, path, res);
        SearchPath(root->right, sum - root->val, path, res);
        path.pop_back();
    }
};