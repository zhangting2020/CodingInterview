/*************************************************************************
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

解题思路：
先序遍历二叉树，找到每一条路径。这里每次将期望值减去当前结点，因此最终当前结点与
期望值相等的时候，并且该结点是叶节点，则是一条满足要求的路径。
1. 每次将当前访问的结点加入到路径trace中；若当前的结点的值等于期望值，并且为叶结点，把这一条路径加入path
2. 否则，当左子树不为空，继续寻找路径；当右子树不为空，继续寻找路径
3. 回到当前结点的父节点
*************************************************************************/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > path;
        if(root == NULL)
            return path;
        vector<int> trace;
        Findpath(root, expectNumber, path, trace);
        return path;
    }
    
    void Findpath(TreeNode* root, int expectNumber, vector<vector<int> >& path, vector<int>& trace)
    {
        if(root == NULL)
            return;
        //将当前的结点加入路径
        trace.push_back(root->val);
        bool isleaf = (root->left == NULL && root->right == NULL);
        //若当前结点是叶节点并且当前和为要求的数值，则构成一条路径
        if(isleaf && root->val == expectNumber)
        {
            path.push_back(trace);
            trace.pop_back();   //把当前结点去除
            return;
        }
        //如果不是叶节点就遍历它的子节点
        if(root->left != NULL)
            Findpath(root->left, expectNumber - root->val, path, trace);
        if(root->right != NULL)
            Findpath(root->right, expectNumber - root->val, path, trace);
        
        //返回父节点之前,从路径里删除当前路径
        trace.pop_back();
        
            
    }

};