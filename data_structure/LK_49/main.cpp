//https://leetcode-cn.com/submissions/detail/167855191/

//43. 字符串相乘
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2)
    {
        string s(num1.size() + num2.size(),'0');
        for (int i = num1.size() - 1;i >= 0;--i)
        {
            for (int j = num2.size() - 1;j >= 0;--j)
            {
                int res = (num1[i] - '0') * (num2[j] - '0') + (s[i+j+1] - '0');
                s[i + j + 1] = res % 10 + '0';
                s[i + j] += res / 10;
            }
        }
        for (int i = 0;i <s.size();++i)
        {
            if (s[i] != '0')
                return s.substr(i);
        }
        return "0";
    }
};
/*
class Solution {
public:
    string addString(string &num1,string &num2)
    {
        int i = num1.size() - 1,j = num2.size() - 1;
        int count = 0;
        string result;
        while (i >= 0 || j >= 0 || count != 0)
        {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int res = x + y + count;
            result.push_back(res % 10);
            count = res / 10;
            --i,--j;
        }
        reverse(result.begin(),result.end());
        for (auto &e : result)
            e += '0';
        return result;
    }
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        string result = "0";
        for (int i = num2.size() - 1;i >= 0;--i)
        {
            string str;
            int count = 0;//判断进位
            for (int j = num2.size() - 1;j > i;--j)
                str.push_back(0);
            int y = num2.at(i) - '0';
            for (int j = num1.size() - 1;j >= 0;--j)
            {
                int x = num1.at(j) - '0';
                int res = x * y  + count;
                str.push_back(res % 10);
                count = res / 10;
            }
            while (count)
            {
                str.push_back(count % 10);
                count /= 10;
            }
            reverse(str.begin(),str.end());
            for (auto &e:str)
                e += '0';
            result = addString(result,str);
        }
        return result;
    }
};
*/
int main()
{
    string s1 = "12",s2 = "24";
    Solution S;
    S.multiply(s1,s2);
}