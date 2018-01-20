/**************************************************************************
��Ŀ����
Say you have an array for which the i th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

��Ŀ���������һ�����飬λ�ö�Ӧ�ص���Ĺ�Ʊ�۸�����������
����˼·��ÿ����һ��ļ۸����ǰһ��ʱ������Ĳ�ۣ����뵽��������ȥ�������õ������������
****************************************************************************/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxprofit = 0;
        if(prices.empty())
            return maxprofit;
        vector<int>::iterator it = prices.begin();
        for(it; it != prices.end() - 1; ++it)
        {
            if(*it < *(it + 1))
                maxprofit += *(it + 1) - *it;
        }
        return maxprofit;
    }
};