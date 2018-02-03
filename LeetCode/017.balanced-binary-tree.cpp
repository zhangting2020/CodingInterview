/*
题目描述
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined 
as a binary tree in which the depth of the two subtrees of 
every node never differ by more than 1.
题目解读：
判断二叉树是不是高度平衡的。子树的深度差不能超过1.
解题思路：
后续遍历结点，每访问一个结点，当它的左右子树都是平衡二叉树时，
计算它的左右子树的深度差判断当前结点
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
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        int depth = 0;
        return isBalancedCore(root, depth);
            
        
    }
    bool isBalancedCore(TreeNode *root, int &depth)
    {
        if(root == NULL)
        {
            depth = 0;
            return true;
        }
        //后续遍历记录深度
        int ldepth = 0, rdepth = 0;
        bool left = isBalancedCore(root->left, ldepth);     
        bool right = isBalancedCore(root->right, rdepth);
        if(left && right)   //当前结点的左右子树都是平衡二叉树
        {
            int diff = ldepth - rdepth;
            if(diff >= -1 && diff <= 1)  //左右子树深度相差为1
            {
                depth = 1 + (ldepth > rdepth ? ldepth : rdepth);  //当前结点的深度等于左右子树中最大的深度 + 1
                return true;   //以当前结点为根的树是平衡二叉树
            }
        }
        return false;
    }
};
