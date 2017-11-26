/*******************************************************
题目描述:输入一个整数数组，实现一个函数来调整该数组中数字的顺序,使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分,并保证奇数和奇数，偶数和偶数之间的相对位置不变。
解题思路：如果不需要保持奇数，偶数的相对位置不变，可以用快排的思路，两个指针分别指向头和尾，交换不符合要求的数。
本题要保持相对位置不变，因此可以考虑找到第一个偶数的位置，把它后面的奇数都插入到它前面。
注意：vector的插入和删除会使迭代器失效
********************************************************/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>::iterator peven = array.begin();
        vector<int>::iterator podd = array.begin();
        while(peven != array.end())  //找到第一个偶数的位置
        {
            if((*peven & 1) == 1)
                ++peven;
            else
                break;
        }
        for(podd; podd != array.end(); )
        {
            if( (*podd & 1) == 1 && podd > peven)   //找到奇数，并且在第一个偶数后面
            {
                int distance = podd - peven;
                peven = array.insert(peven, *podd); //偶数所在位置peven插入后面的这个奇数
                ++peven;
                podd = array.erase(peven + distance);
            }
            else
                ++podd;
        }
        
        
    }
};