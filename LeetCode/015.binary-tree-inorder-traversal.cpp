/*********************************************************************
题目描述
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},

   1
    \
     2
    /
   3
return[1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
confused what"{1,#,2,3}"means? > read more on how binary tree is 
Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as"{1,2,3,#,#,4,#,#,5}".
题目解读：
输出中序遍历二叉树的结果，使用迭代的解法。
解题思路：
使用栈。一直沿着左边的路径将节点入栈，当找到最左的节点时，将其出栈。
保存该节点的值。然后将指针指向其右孩子。
********************************************************************/
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
        TreeNode* curnode = root;
        stack<TreeNode*> nodes;
        while(!nodes.empty() || curnode != NULL)
        {
            while(curnode)
            {
                nodes.push(curnode);
                curnode = curnode->left;
            }
            if(!nodes.empty())
            {
                curnode = nodes.top();
                nodes.pop();
                result.push_back(curnode->val);
                curnode = curnode->right;
            }
        }
        return result;
    }
};