//跳石板
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
class Solution
{
public:
    void GetMinStep(const int &N,const int &M)
    {

        int n,m;
        while (cin >> n >> m)
        {
            //dp[i]表示到i石板最少的步数
            vector<int>dp(m + 1,INT_MAX);
            //base case
            dp[n] = 0;
            for (int i = n;i <= m;++i)
            {
                if (dp[i] == INT_MAX)
                    continue;
                for (int j = 2;(j * j) <= i;++j)
                {
                    if (i % j == 0)
                    {
                        if (i + j <= m)
                            dp[i + j] = min(dp[i] + 1,dp[i + j]);
                        if (i + (i / j) <= m)
                            dp[i + (i / j)] = min(dp[i] + 1,dp[i + (i / j)]);
                    }
                }
            }
            if (dp[m] == INT_MAX)
                dp[m] = -1;
            cout<<dp[m]<<endl;
        }
    }
};
int main()
{
    int N = 0,M = 0;
    Solution S;
    S.GetMinStep(N,M);
    return 0;
}

/*
//参数解析
#include<iostream>
#include<string>
#include <vector>
using namespace std;
class Solution
{
public:
    void Analysis(const string &str)
    {
        string ans = "";
        vector<string> res;
        int flag = 0;
        for (int i = 0;i < str.size();++i)
        {
            if (str[i] == '"')
                flag = 1;
            else if (str[i] == ' ' && flag == 0)
            {
                res.push_back(ans);
                ans = "";
            }
            else
            {
                ans += str[i];
            }
        }
        res.push_back(ans);
        int count = res.size();
        cout<<count<<endl;
        for (int i = 0;i < res.size();++i)
            cout<<res[i]<<endl;
    }
};

int main()
{
    string str;
    getline(cin,str);
    Solution S;
    S.Analysis(str);
    return 0;
}
*/