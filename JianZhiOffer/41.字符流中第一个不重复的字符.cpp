/***********************************************************************************************************
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
解题思路：
1.首先构造一个哈希表，key为字符ASCII码，value初始化为-1。
2.读入一个字符，查哈希表对应位置，如果为-1表示未出现过，则将该位置的值更新为字符在字符流中的索引；
  若哈希表对应位置大于等于0，表示已经出现过，因此将该位置的值更新为-2
3.当前字符流中第一次出现的字符，只需要从开头查哈希表，第一个值大于等于0的key，其key就是第一次出现的
  字符的ASCII码
************************************************************************************************************/
class Solution
{
public:
    Solution():index(0)
    {
        for(int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(occurrence[ch] == -1)  //该字符还未出现
            occurrence[ch] = index;  //哈希表中对应位置更新value
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;   //该字符已经出现过，所以哈希表中的值是正数即索引
        ++index;
            
            
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = 0x7fffffff;
        for(int i = 0; i < 256; ++i)
        {
            if(occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }
        if(ch == '\0')
            return '#';
        else
            return ch;
    
    }
private:
    int occurrence[256]; //哈希表
    int index;

};