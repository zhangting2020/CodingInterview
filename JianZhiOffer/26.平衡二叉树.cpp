/*********************************************************************************************
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
解题思路：后续遍历结点，每访问一个结点，当它的左右子树都是平衡二叉树时，计算它的左右子树的深度差
          判断当前结点是不是平衡二叉树。
**********************************************************************************************/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
            return true;
        int depth = 0;
        return IsBalance(pRoot, depth);

    }
    
    bool IsBalance(TreeNode* pRoot, int& depth)
    {
        if(pRoot == NULL)
        {
            depth = 0;
            return true;
        }
        //后续遍历记录深度
        int ldepth = 0, rdepth = 0;
        bool left = IsBalance(pRoot->left, ldepth);     
        bool right = IsBalance(pRoot->right, rdepth);
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