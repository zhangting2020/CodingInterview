/******************************************************************************************
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。

解题思路：例如序列 4， 8， 6， 12， 16， 14， 10
1. 后续遍历的最后一个结点是根节点，因此找到最后一个结点将序列分为左右子树。左子树结点都小于根
右子树结点均大于根。
2. 从序列开始找到比根结点大的位置，即为右子树开始。此时左边的元素均小于根，因此满足左子树要求
3. 判断右子树的结点是不是都小于根，否，则不是二叉搜索树
4. 递归地判断左， 右两边的元素是不是二叉搜索树。

注意：递归终止条件，即当前序列只剩一个元素。
*******************************************************************************************/


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        vector<int>::iterator start = sequence.begin();
        vector<int>::iterator end = sequence.end();
        
        return VerifySubSquenceofBST(start, end);
        
        
    }
    bool VerifySubSquenceofBST(vector<int>::iterator start, vector<int>::iterator end)
    {
        if(end - start == 1)   //只有一个元素
            return true;
        
        vector<int>::iterator it = start;
        int root = *(end - 1);
        
        while(it != end)   //寻找左右子树分界点，最终it指向右子树第一个元素
        {
            if(*it < root)
                ++it;
            else
                break;
        }
        
        vector<int>::iterator it2 = it;
        while(it2 != end)       //判断右子树结点是否都小于根节点，如果否，则不是二叉搜索树
        {
            if(*it2 < root)
                return false;
            ++it2;
        }
        
        bool left = true;
        if(it != start)
            left = VerifySubSquenceofBST(start, it);   //左子树起始到右子树开头元素
        bool right = true;
        if(left && it != end)
            right = VerifySubSquenceofBST(it, end - 1); //右子树起始到根节点
        
        return (left && right);

    }
};