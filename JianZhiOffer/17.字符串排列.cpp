/*********************************************************************************************
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串
abc,acb,bac,bca,cab和cba。
解题思路：递归的将字符串不断划分为更小的串。每次取字符串第一个字符，与后面的字符依次交换。
          1. 例如abc，循环地交换a与剩下的字符bc。第一次循环的结果为abc
		  2. 递归地处理剩下的字符串bc，交换后为cb,结果为acb
		  3. 此时以a为首的字符串排列已完成，交换a与b,结果为bac;然后递归地处理ac字符串
注意：当有重复字符时，不需要交换，直接进行下一轮的循环；
      结果要求以字典顺序，因此需要在返回结果前，对结果进行排序
***********************************************************************************************/
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.length() == 0)
            return result;
        int start = 0;
        Permutation(str, start, result);
        sort(result.begin(), result.end());
        return result;
    }
    
    void Permutation(string& str, int start, vector<string>& result)
    {
        if(str[start] == '\0')
        {
            result.push_back(str);
            return;
        }
            
        for(int i = start; str[i] != '\0'; ++i)  //遍历字符串，交换首字符与剩下的每个字符
        {
            //交换当前首字符与剩下的每一个字符
            if(i != start && str[i] == str[start])   //若要交换的字符相同，执行下一次循环
                continue;
            char temp = str[i];
			str[i]= str[start];
			str[start] = temp;
            Permutation(str, start + 1, result);   //处理后续字符串
            //恢复到原始串
            temp = str[i];
			str[i]= str[start];
			str[start] = temp;
        }
    }
};