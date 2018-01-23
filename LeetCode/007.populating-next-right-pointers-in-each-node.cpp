/********************************************************************************************************
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, 
the next pointer should be set toNULL. Initially, all next pointers are set to NULL.
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
题目解读：给填充二叉树的next指针，指向同一层的右结点。
解题思路：
使用队列先进先出的特点，处理队列0时，下一层的结点存储在队列1中；反之同理。
********************************************************************************************************/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        deque<TreeLinkNode*> Layer[2];
        Layer[0].push_back(root);
        int i = 0;
        while(!Layer[0].empty() || !Layer[1].empty())
        {
            while(!Layer[i].empty())
            {
                TreeLinkNode* curNode = Layer[i].front();
                Layer[i].pop_front();
            	//暂存当前层的子节点
           	 	if(curNode->left)
                	Layer[1-i].push_back(curNode->left);
           		if(curNode->right)
                	Layer[1-i].push_back(curNode->right);
           		 //填补当前层节点的指针
           		if(Layer[i].empty())
                	curNode->next = NULL;
            	else
                	curNode->next = Layer[i].front();
            }
            i = 1-i;  //切换要修改指针的层的编号
        }
    }
};
