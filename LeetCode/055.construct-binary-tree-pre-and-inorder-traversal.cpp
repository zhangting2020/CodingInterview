/*
题目描述
Given preorder and inorder traversal of a tree, construct the binary tree.
Note: 
You may assume that duplicates do not exist in the tree.
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
   3
   / \
  9  20
    /  \
   15   7
题目解读：
给定先序和中序遍历的结果，构建一个二叉树。假设不存在相同的结点。
解题思路：
先序遍历的第一个结点为根节点，根据根节点将中序遍历结果划分为左右子树，然后递归地构建左右子树：
1.先构建新的根节点
2.若先序beign和end相等：
  a.若中序的begin和end相等 && 先序的begin和中序的end相等（根左右；左根右，最后构建的结点一定相同）
	则构建完成，返回根节点
  b.无法构成二叉树
3.2不满足时，在中序里寻找根节点位置：
  a.若找不到根节点，不能构成二叉树
  b.否则，计算左子树结点个数，在先序中找到左右子树序列，递归地构建左子树和右子树
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;
        return buildTreeCore(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        
    }
    
    TreeNode *buildTreeCore(vector<int>::iterator pbegin, vector<int>::iterator pend,
                           vector<int>::iterator inbegin, vector<int>::iterator inend)
    {
        //构建根节点
        int rootval = *pbegin;
        TreeNode *root = new TreeNode(rootval);
        
        if(pbegin == pend)
        {
            if(inbegin == inend && pbegin == inend)  //已经遍历到最后一个要构建的结点
                return root;
            else
                return NULL;  //无法构成二叉树
        }
        //在中序中找到根节点
        vector<int>::iterator root_inorder = inbegin;
        while(root_inorder != inend && *root_inorder != rootval)
            ++root_inorder;
        if(root_inorder == inend)
            return NULL;
        int leftLength = root_inorder - inbegin;  //左子树的长度
        vector<int>::iterator leftPreEnd = pbegin + 1 + leftLength; //最终使leftPreEnd指向先序中左子树最后一个结点的下一位
        //构建左子树
        if(leftLength > 0)
        {
            root->left = buildTreeCore(pbegin + 1, leftPreEnd, inbegin, root_inorder);
        }
        //构建右子树
        if(root_inorder != inend)
            root->right = buildTreeCore(leftPreEnd, pend, root_inorder + 1, inend);
        return root;
    }
    
};