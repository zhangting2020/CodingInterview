/*
题目描述
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).
For example:
Given binary tree{3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]
题目解读：
给定一二叉树，返回自底向上的层序遍历结果。
解题思路：
1. 使用队列暂存下一层的结点，每当从队列中弹出一个结点时，将其左右子结点存入队列。同时，将该结点的值加入
结果。
2. 每一层的结点处理完。将该层的结果存入result。
3. 最后对result翻转，得到bottom-up的层序遍历结果。
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            vector<int> level;  //存储当前层的结点数值
            int levelNum = nodes.size();  //当前层的结点数
            for(int i = 0; i < levelNum; ++i)
            {
                TreeNode* curNode = nodes.front();
                nodes.pop();
                //把当前结点的左右子结点存储下来
                if(curNode->left)
                    nodes.push(curNode->left);
                if(curNode->right)
                    nodes.push(curNode->right);
                level.push_back(curNode->val);
            }
            result.push_back(level); 
        }
        reverse(result.begin(), result.end());
        return result;
    }
};