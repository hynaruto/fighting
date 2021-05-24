//字符串倒置
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    string Fun( string &str)
    {
        if (str.empty())
            return "";
        reverse(str.begin(),str.end());
        auto it = str.begin();
        auto start = it;
        while (it != str.end())
        {
            while (it != str.end() && *it != ' ')
                ++it;
            reverse(start,it);
            while (it != str.end() && *it == ' ')
                ++it;
            start = it;
        }
        return str;
    }
};
int main()
{
    Solution S;
    string s;
    getline(cin,s);
    S.Fun(s);
    cout<<s<<endl;
    return 0;
}