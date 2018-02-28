/**********************************************************************
��Ŀ����
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?
��Ŀ�����
��һ������˳ʱ����ת90�ȡ�
����˼·��
1 2 3     1 4 7     7 4 1
4 5 6     2 5 8     8 5 2
7 8 9     3 6 9     9 6 3
��һ�����Է������ת�ã��ڶ��������з�ת��
**********************************************************************/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        //����ת��
        for(int i = 0; i < n; ++i)
        {
            for(int j = i + 1; j < n; ++j)   //��j = i��λ�ÿ�ʼ����Ϊi=j��λ��ת��ʱ����
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            //����y�ᷭת,�൱�����з�ת
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};