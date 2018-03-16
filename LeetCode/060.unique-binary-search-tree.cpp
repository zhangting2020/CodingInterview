/*
题目描述
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
题目解读：
给定n，生成所有唯一的二叉搜索树。二叉搜索树的特点：左子树比根小，右子树比根大。
解题思路：
递归地生成二叉搜索树。将1-n的n个数字划分为两部分，根结点和子树结点。
1.依次选择1-n中的结点k作为根节点，根节点左边1~k-1作为左子树结点；根节点右边的k+1~n作为右子树结点。
2.递归地构造左右子树，直至左右子树的结点都被加入树中。
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
    vector<TreeNode *> generateTrees(int n) {
        
        return generateTreesCore(1, n);
    }
    
    vector<TreeNode *> generateTreesCore(int begin, int end)
    {
        vector<TreeNode *> result;
        if(begin > end)
            result.push_back(NULL);
        for(int k = begin; k <= end; ++k) //以k为根生成左右子树
        {
            vector<TreeNode *> leftRoots = generateTreesCore(begin, k - 1);  //左子树根节点的集合
            vector<TreeNode *> rightRoots = generateTreesCore(k + 1, end);  //右子树根节点的集合
            for(int i = 0; i < leftRoots.size(); ++i)   //以k为根生成的左右子树，进行组合
            {
                for(int j = 0; j < rightRoots.size(); ++j)
                {
                    TreeNode *root = new TreeNode(k);
                    root->left = leftRoots[i];
                    root->right = rightRoots[j];
                    result.push_back(root);  //放入一棵树的根
                }
            }
        }
        return result;
    }
};