#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution
{
public:
    string AddLongInteger(string &addend,string &augend)
    {
        string s1,s2;
        while (cin >>s1 >>s2)
        {
            int max = s1.size() > s2.size() ? s1.size() : s2.size();
            reverse(s1.begin(),s1.end());
            reverse(s2.begin(),s2.end());
            int tmp = 0,k = 0;
            vector<int> nums(512,0);
            for (int i = 0;i < max;++i)
            {
                int a = 0,b = 0;
                if (i < s1.size())
                    a = s1[i] - '0';
                else
                    a = 0;
                if (i < s2.size())
                    b = s2[i] - '0';
                else
                    b = 0;
                int res = a + b + tmp;
                tmp = res > 9 ? 1 : 0;
                nums[k++] = res % 10;
            }
            if (tmp > 0)
            {
                nums[k] = 1;
                for (int j = k;j >= 0;--j)
                    cout<<nums[j];
            }
            else
            {
                for (int j = k - 1;j >= 0;--j)
                    cout<<nums[j];
            }
        }
        cout<<endl;
    }
};
int main()
{
    string s1,s2;
    Solution S;
    S.AddLongInteger(s1, s2);
    return 0;
}