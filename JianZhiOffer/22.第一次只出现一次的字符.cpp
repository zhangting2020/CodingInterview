/****************************************************************************************
题目描述
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
解题思路：利用哈希表，key为字符的ASCII码，value为字符出现的次数。
          1. 初始化哈希表，使值均为0；
		  2. 遍历字符串，更新每个字符出现的次数
		  3. 遍历字符串，查哈希表，看该字符是否出现次数为1，是则返回位置
*****************************************************************************************/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() == 0)
            return -1;
        const int size = 256;
        unsigned int hashTable[size];
        for(unsigned int i = 0; i < size; ++i)
            hashTable[i] = 0; 
        
        size_t length = str.length();
        for(size_t i = 0; i < length; ++i)
        {
            hashTable[str[i]]++;
        }
        for(size_t i = 0; i < length; ++i)
        {
            if(hashTable[str[i]] == 1)
                return i;
        }
        return -1;
    }
};