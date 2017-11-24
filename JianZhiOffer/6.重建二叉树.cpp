题目：重建二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
思路：先序遍历第一个元素为根节点。在中序中根据根节点划分左右子树。递归地构建二叉树
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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty() || vin.empty())
            return NULL;
        return ConstructCore(pre.begin(), pre.end() - 1,vin.begin(),vin.end() - 1);
    }
    
    TreeNode* ConstructCore(vector<int>::iterator pre_begin, vector<int>::iterator pre_end,
                            vector<int>::iterator vin_begin, vector<int>::iterator vin_end)
    {
        //构建根节点，根节点=先序遍历的第一个元素
        int RootVal = *pre_begin;
        TreeNode *root = new TreeNode(RootVal);
        //递归结束条件
        if(pre_begin == pre_end)   
        {
            if(vin_begin == vin_end && *pre_begin == *vin_end)  //说明所有元素都已被构建到树中了
                return root;
            else
                return NULL;  //所给的两个序列不能构建二叉树
        }
        
        //在中序里寻找对应的根节点位置
        vector<int>::iterator rootInorder = vin_begin;  
        while(rootInorder < vin_end && *rootInorder != RootVal)   
            ++rootInorder;
        
        if(rootInorder > vin_end && *rootInorder != RootVal)  //未找到
            return NULL;
        
        int leftLength = rootInorder - vin_begin;   //左子树的元素个数
        vector<int>::iterator leftPreEnd = pre_begin + leftLength;   //在先序中找到左子树的结束位置
        //构建左子树
        if(leftLength > 0)
        {
            root->left = ConstructCore(pre_begin + 1,leftPreEnd, vin_begin, rootInorder - 1);
        }
        //构建右子树
        //if(leftLength < pre_end - pre_begin)
        if (vin_end - rootInorder > 0)
        {
            root->right = ConstructCore(leftPreEnd + 1, pre_end, rootInorder + 1, vin_end);
        }
        return root;

    }
};