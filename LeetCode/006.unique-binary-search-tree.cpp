/******************************************************************************************************************************
题目描述
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
题目解读：
给定一个数，求1...n的序列能组成多少个不同的二叉搜索树。
解题思路：
G(n):当序列长度为n时，二叉搜索树的个数
F(i,n),1<=i<=n:以i为根节点时，能组成的二叉搜索树的数量,序列长度为n。
因此，当序列长度为n时，二叉搜索树的个数
G[n] = F(1,n) + F(2,n) + ...+F(n,n)
F(i,n) = G(i-1) * G(n-i)     1<=i<=n-i
综合两个式子，有：
G(n) = G(0)*G(n-1)+G(1)*G(n-2)+...G(n-1)*G(0)
特别的：G(0)=G(1)=1
******************************************************************************************************************************/
class Solution {
public:
    int numTrees(int n) {
        int* G = new int[n + 1];
        G[0] = G[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        int res = G[n];
        // delete[] G;
        return res;
    }
};