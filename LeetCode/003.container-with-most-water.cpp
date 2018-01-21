/**************************************************************************
��Ŀ����
Given n non-negative integers a1 , a2 , ..., an , where each represents a point
at coordinate (i, ai ). n vertical lines are drawn such that the two endpoints of 
line i is at (i, ai ) and (i, 0). Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.
Note: You may not slant the container.
��Ŀ�����
�����е���ֵΪ�ߵĸ߶ȡ��ҵ������ߣ���x�ṹ�ɵ����������ɵ�ˮ��ࡣ
����˼·��
���ɵ������ݻ���������֮��ľ��룬���������еĶ̱߾�����
1.����ָ�룬�ֱ�ָ����������ҵĸ߶ȣ�
2.ÿ�θı���̵ıߵ�ָ���ָ��ʹ�����м��ƶ�
3.���㵱ǰ��������̱� * �����ߵľ��룬����֮ǰ�ľ���Աȱ���������
*****************************************************************************/
class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        if(height.empty())
            return max_area;
        int left = 0;
        int right = height.size() - 1;
        int curArea = 0;
        int curHeight = 0;
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                curArea = height[left] * (right - left);
                left++;
            }
            else
            {
                curArea = height[right] * (right - left);
                right--;
            }
            max_area = max(max_area, curArea);
        }
        return max_area;
    }
};

