/*****************************************************************************************************
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
解题思路:相同的数异或为0
1. 首先将数组中所有数都异或，相同的数经过异或为0，最终的结果就是两个只出现了一次的数异或的值
2. 找到异或结果中第一个为1的位，因为这一位为1，代表这两个只出现一次的数，这一位是不相同的
3. 根据第一个为1的位的位置，将数组可以划分为两部分，每一部分中分别包含了一个只出现了一次的数
4. 将两部分分别异或就得到了两个只出现一次的结果 
******************************************************************************************************/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty())
        {
            num1 = NULL;
            num2 = NULL;
        }
        int ResultExclusiveOr = 0;
        //所有数做异或，最终的结果是两个只出现一次的数异或的结果
        for(vector<int>::iterator it = data.begin(); it != data.end(); ++it)
        {
            ResultExclusiveOr ^= *it;
        }
        //找到异或结果中第一个不为0的位
        unsigned int indexBit = FindFirstBit1(ResultExclusiveOr);
        *num1 = *num2 = 0;
        for(vector<int>::iterator it = data.begin(); it != data.end(); ++it)
        {
            if(IsBit1(*it, indexBit))     //以第Index位是否为1来将数组划分为两类，异或找出出现一次的数
                *num1 ^= *it;
            else
                *num2 ^= *it;
        }
    }
    
    unsigned int FindFirstBit1(int num)
    {
        int index = 0;
        while( ((num & 1) == 0) && (index < 8 * sizeof(int)))   //当num与1相与为0，说明num最后一位为0
        {
            num = num >> 1; 
            ++index;
        }
        return index;
    }
    
    bool IsBit1(int num, unsigned int index) //判断第index位是不是1
    {
        num = num >> index;  //将第index位移到最后一位
        return (num & 1);
    }
};