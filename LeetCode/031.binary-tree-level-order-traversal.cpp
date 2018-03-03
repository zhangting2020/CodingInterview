/*
题目描述
Given a binary tree, return the level order traversal of its nodes' 
values. (ie, from left to right, level by level).
For example:
Given binary tree{3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
题目解读：
层序遍历二叉树。
解题思路：
使用队列。每次访问该层节点时，保存该层每个节点的左右子节点；并且将该层
节点的值保存在结果中。
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        vector<int> level; //保存每层的节点的值
        deque<TreeNode*> nodes; 
        nodes.push_back(root);
        TreeNode* curNode;
        int num[2] = {1, 0};
        int i = 0;
        while(!nodes.empty())
        {
            while(num[i])
            {
                --num[i];
                curNode = nodes.front();
                nodes.pop_front();
                level.push_back(curNode->val);
                if(curNode->left)
                {
                    nodes.push_back(curNode->left);
                    ++num[1-i]; //保存下一层的节点数
                }
                if(curNode->right)
                {
                    nodes.push_back(curNode->right);
                    ++num[1-i];
                }
            }
            if(!level.empty())
            {
                result.push_back(level);
                level.clear();
            }
            i = 1 - i;
        }
        return result;
    }
};

