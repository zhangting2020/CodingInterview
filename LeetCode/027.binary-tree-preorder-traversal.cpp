/*
题目描述
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},

   1
    \
     2
    /
   3

return[1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
题目解读：
先序遍历二叉树。使用迭代方法。
解题思路：
1.每次访问一个节点时，将其值加入结果中。
2.如果该节点的右子结点不为空，就将右子节点入栈，以便稍后访问
3.然后访问该节点的左子节点。若左子节点为空，则将栈顶节点出栈。
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> nodes;
        TreeNode* curNode = root;
        while(curNode != NULL)
        {
            result.push_back(curNode->val);
            if(curNode->right != NULL)
                nodes.push(curNode->right);
            curNode = curNode->left;
            if(curNode == NULL && !nodes.empty())
            {
                curNode = nodes.top();
                nodes.pop();
            }
        }
        return result;
    }
};