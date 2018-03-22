/*
题目描述
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},

   1
    \
     2
    /
   3

return[3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?
题目解读：
给定一个二叉树，返回后续遍历的结果。
解题思路：
使用迭代法。设计一种新的前序遍历，根右左，然后对结果进行翻转，得到左右根的后序遍历结果。
1.栈内放入二叉树的根节点。
2.栈内结点弹出，将其值放入结果；然后分别将弹出的结点的左右子结点入栈。
3.当栈内结点全部弹出时，对结果进行翻转。
经过上面的过程，每次出栈的时候，都是先出右结点，因此存入结果中的值总是按照根右左的顺序。
再经过翻转得到左右根的后续遍历结果。
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            TreeNode* curNode = nodes.top();
            res.push_back(curNode->val);
            nodes.pop();
            if(curNode->left)
                nodes.push(curNode->left);
            if(curNode->right)
                nodes.push(curNode->right);
            
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

