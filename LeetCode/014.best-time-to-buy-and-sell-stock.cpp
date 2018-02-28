********************************************************************
题目描述
Say you have an array for which the i th element is the price of 
a given stock on day i.
If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm 
to find the maximum profit.
题目解读：
给定一个数组，第i个元素是第i天的股票价格。如果只能完成一次交易，设计
一个算法获得最大收益。
解题思路：
从头遍历，如果当前的价格更小，更新最小价格；否则若当前价格减去最小价格
比最大收益大，则更新最大收益。
********************************************************************/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1)
            return 0;
        int minprice = 0x7FFFFFFF;
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); ++i)
        {
            if(prices[i] < minprice)
                minprice = prices[i];
            else if(prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
    }
};