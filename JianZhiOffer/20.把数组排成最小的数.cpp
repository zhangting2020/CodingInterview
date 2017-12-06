/**********************************************************************************************
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

解题思路：1. 首先将数组中的每个数转换成string类型，存放在strNumbers的vector中
          2. 对strNumbers中的每个字符串排序，按由小到大的规则，这里用sort函数
		  3. 依次把排序后的字符串挨个拼接起来就是最小的数
注意：1. sort函数，需要自己写比较规则，需要由小到大就return s1 < s2;由大到小，则return s1 > s2
      2. 数字转字符串 sprintf(str, "%d", *it); 字符串后面拼接str.append(str2);
	  3. char str[10],用来存放转换为字符串的数字，这是因为int最大的数占10位
	  4. 最后要返回的最小值可能会超过int,存在大数问题，因此使用string 作为返回值类型
	  4. cmp函数写在类中，但必须为static，否则编译错误，因为非static函数需要对象才能调用。static函数不
	  属于任何对象。
************************************************************************************************/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string result;
        if(numbers.empty())
            return result;
        char str[10];
        vector<string> strNumbers;
        vector<int>::iterator it = numbers.begin();
        for(it; it != numbers.end();++it)
        {
            sprintf(str, "%d", *it);
            strNumbers.push_back(str);
        }
        
        sort(strNumbers.begin(), strNumbers.end(), cmp);
        //把排列好的字符串拼接起来
        for(vector<string>::iterator iter = strNumbers.begin(); iter != strNumbers.end(); ++iter)
        {
            result.append(*iter);
        }
        return result;
    }
    static bool cmp(const string& str1, const string& str2)
    {
        string s1 = str1 + str2;
        string s2 = str2 + str1;
        return s1 < s2;    //由小到大排序
    }
};
