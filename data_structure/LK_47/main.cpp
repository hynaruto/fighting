//https://leetcode-cn.com/problems/add-strings/

//415. 字符串相加

#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1,j = num2.size() - 1;
        int count = 0;//判断是否有进位
        string result = "";
        while (i >= 0 || j >= 0 || count != 0)
        {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int sum = x + y + count;
            result.push_back(sum % 10 + '0');
            count = sum / 10;
            --i,--j;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{

    Solution S;
    string num1 = "11";
    string num2 = "123";
    S.addStrings(num1,num2);
    return 0;
}