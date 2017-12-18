/****************************************************************************************************
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
解题思路：
1.由于之字形打印结果，偶数层打印时先打左子结点，奇数层打印时先打右子结点，故考虑两个栈
2.当打印偶数层时，先右后左的顺序将当前结点的左右子结点保存在栈s1中；当打印奇数层时，先左后右的顺序将
  当前结点的左右子结点保存在栈s0中
3.打印每一层时，就打印对应的栈中的结点的值。
*****************************************************************************************************/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > result;
        if(pRoot == NULL)
            return result;
    
        stack<TreeNode*> s0;
        stack<TreeNode*> s1;
        vector<int> layer;
        int flag = 0;
        s0.push(pRoot);
        TreeNode* current;
        while(!s0.empty() || !s1.empty())
        {
            if(flag == 0)   //打印的是偶数层
            {
                flag = 1;
            	while(!s0.empty())  //当偶数层还未打印完
            	{
                    current = s0.top();
                    s0.pop();
                    if(current->left)            //结点先左后右的顺序入栈
                        s1.push(current->left);
                	if(current->right)
                    	s1.push(current->right);
               		 layer.push_back(current->val);  //将打印的结点的值存入当前层
                }
                if(!layer.empty())
                {
                    result.push_back(layer);
                    layer.clear();
                }
            }
            if(flag == 1)
            {
                flag = 0;
                while(!s1.empty())    //打印奇数层
                {
                    current = s1.top();
                    s1.pop(); 
                    if(current->right)   //结点先右后左顺序入栈
                        s0.push(current->right);
                    if(current->left)
                        s0.push(current->left);
                    layer.push_back(current->val);
                }
                if(!layer.empty())
                {
                    result.push_back(layer);
                    layer.clear();
                }
            }
        }
        return result;
    }
    
};