/*********************************************************************************************************
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
解题思路：
按层打印，可以使用队列，先进先出的特点。
每访问一个结点，就把它的左右结点存入队列能够实现每访问一个结点，就把它的左右结点存入队列；
每次从队列弹出队首结点，保存它的左右子结点进队列
next,和current记录下一层要打印的结点数，和当前层打印的结点数，用来控制当前层所有结点是否访问完
*********************************************************************************************************/
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
            vector<int> layer;
            deque<TreeNode*> nextLayer;
            nextLayer.push_back(pRoot);
            TreeNode* pNode;
            int current = 1;  //当前层的结点数
            int next = 0;
            
            while(!nextLayer.empty())
            {
                pNode = nextLayer.front();
                layer.push_back(pNode->val);
                nextLayer.pop_front();
                current--;
                if(pNode->left)
                {
                    nextLayer.push_back(pNode->left);
                    ++next;
                }
                if(pNode->right)
                {
                    nextLayer.push_back(pNode->right);
                    ++next;
                }
                if(current == 0)   //当前层已经访问完
                {
                    result.push_back(layer);  //当前层的结点值存入
                    layer.clear();   
                    current = next;   //当前的结点数置为下一层要打印的结点数
                    next = 0;
                }
            }
            return result;
        
        }
    
};