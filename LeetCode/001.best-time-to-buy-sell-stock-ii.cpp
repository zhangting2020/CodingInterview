/**************************************************************************
题目描述
Say you have an array for which the i th element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

题目解读：给定一个数组，位置对应地当天的股票价格。求最大的利益
解题思路：每当后一天的价格大于前一天时，就求的差价，加入到总利润上去，最后求得的利润即最大利润
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