/*
题目描述
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
题目解读：
给二叉树填充右指针。
解题思路：
层序遍历。将每一层的结点连接起来。
*/

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
        queue<TreeLinkNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int levelNum = nodes.size(); //该层的结点数
            for(int i = 0; i < levelNum; ++i)
            {
                TreeLinkNode* curNode = nodes.front();
                nodes.pop();
                if(curNode->left)
                    nodes.push(curNode->left);
                if(curNode->right)
                    nodes.push(curNode->right);
                if(i != levelNum - 1)
                    curNode->next = nodes.front();
                else
                    curNode->next = NULL;
            }
        }
    }
};
