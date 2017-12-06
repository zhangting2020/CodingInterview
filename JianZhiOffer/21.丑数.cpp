/******************************************************************************************
题目描述：
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
解题思路：把已有的丑数乘以2，3或5得到的一定是丑数。
          1.如果已有的丑数乘以2小于结果中最后的丑数，那么这个丑数一定已经存在于结果中了。
		    对于乘3或者5来说也是这个道理
		  2. 每一次找到那个乘2,3,5会使得到的丑数大于当前最后一个丑数的三个分界点
		  3.在这三个分界点中找到最小的，这个最小的就是当前最后一个丑数的下一个丑数
注意：1.这里我用的是vector，这道题用数组效果一样。用vector时需要注意，一定要提前分配大小，
        否则vector在不断push的过程中，之前的迭代器会失效，造成程序崩溃。
******************************************************************************************/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0)
            return 0;
        vector<int> uglyNumbers(index,0);    //提前分配index个空间存放丑数结果，避免因Push造成的迭代器失效
        uglyNumbers[0] = 1;
        int next = 1;
        vector<int>::iterator it2, it3, it5;
        it2 = uglyNumbers.begin();   
        it3 = uglyNumbers.begin();
        it5 = uglyNumbers.begin();
        while(next < index)
        {
            int min = Min(*it2 * 2, *it3 * 3, *it5 * 5);
            uglyNumbers[next] = min;
            while(*it2 * 2 <= uglyNumbers[next])
                ++it2;
            while(*it3 * 3 <= uglyNumbers[next])
                ++it3;
            while(*it5 * 5 <= uglyNumbers[next])
                ++it5;
            
            ++next;
        }
        
        int ugly = *(uglyNumbers.end() - 1);
        return ugly;

    }
    
    int Min(int n1, int n2, int n3)
        {
            int min = (n1 < n2) ? n1 : n2;
            min = (min < n3) ? min : n3;
            return min;
        }
};