/*
题目描述
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its 
next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note: 
The solution is guaranteed to be unique.
题目解读：
沿着一个圆形路线，有N个加油站，在位置i上的汽油；量是gas[i]。有一辆车油箱不受限制，并且从位置i到它的
下一个位置i+1的代价是cost[i]。开始时在一个加油站油箱也是空的。如果沿着圆跑一圈，返回开始位置的索引，
否则返回-1。解是唯一的。
解题思路：
思路来源于：https://www.cnblogs.com/felixfang/p/3814463.html
由于解只有一个，并且只有在总的汽油量>=消耗量时，才可能存在一个解。那么如果存在这样的唯一解：
1.总的汽油量-消耗量>=0
2.从唯一正确的start位置出发才能走完一圈回到start。
   diff[i] = gas[i] - cost[i] 表示从当前站点出发，到下一个站点后剩余的油量。也就是说要想到达下一个站点
   diff[i] >= 0。分析：
a. 最开始，站点0是始发站，假设车开出站点p后，油箱空了，假设sum1 = diff[0] +diff[1] + ... + diff[p]，
   可知sum1 < 0；那么前面的0~p位置都不能为始发站，因为每一个diff>=0，从不等式两边减去整数：sum1<0。
b. 根据上面的论述，我们将p+1作为始发站，开出q站后，油箱又空了，
   设sum2 = diff[p+1] +diff[p+2] + ... + diff[q]，可知sum2 < 0。
c. 将q+1作为始发站，假设一直开到了未循环的最末站，油箱没见底儿，
   设sum3 = diff[q+1] +diff[q+2] + ... + diff[size-1]，可知sum3 >= 0。那么继续往后面的站点统计剩余汽油
从上述分析中可以看出，当到达某一站点时，汽油剩余量小于0，那么下一个位置可能会是正确的出发位置。
至于是不是，还要看最终的汽油剩余量是否大于等于0。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if(gas.empty() || cost.empty())
            return -1;
        //remain记录到达当前站点时，累计的汽油剩余量，total是所有站点的汽油总量-消耗
        int index = -1, remain = 0, total = 0;  
        for(int i = 0; i < gas.size(); ++i)
        {
            total += gas[i] - cost[i];
            remain += gas[i] - cost[i];
            if(remain < 0)  //0-i结点都不是正确位置
            {
                index = i;  //记录下最后一个不正确的位置
                remain = 0; //重新出发
            }
        }
        return total >= 0 ? index + 1 : -1;
    }
};