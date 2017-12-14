/**************************************************************************************************************
题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，
那么对应的输出是第一个重复的数字2。

解题思路：
1.将数值为i的数归位到i位置
2.若当期访问的数值为val,位置为i,判断val是否等于i,若相等，则访问下一个数；否则判断val与val位置的数是否相等
 如果相等就找到了重复的数，否则将值为val的数，归位到val位置上
***************************************************************************************************************/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length <= 0)
            return false;
        for(int i = 0; i < length; ++i)
        {
            while(numbers[i] != i)
            {
                if(numbers[i] == numbers[numbers[i]]) 
                {
                    *duplication = numbers[i];
                    return true;
                }
                //交换i位置和numbers[i]位置的两个数，目的是为了使i位置的数值为i
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
        
    }
};
