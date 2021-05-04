//651 4键键盘


#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int MaxA(int N)
    {
        vector<int>dp(N + 1);//dp[i]表示经过i次操作后，屏幕中A的最大个数
        dp[0] = 0;//base case;
        for (int i = 1;i <= N;++i)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 2;j < i;++j)
            {
                //ctrl + c & ctrl + v
                dp[i] = max(dp[i],dp[j - 2] * (i - j + 1));
            }
        }
        return dp[N];
    }
};

int main()
{
    Solution S;
    int res = S.MaxA(9);
    cout<<res<<endl;
    return 0;
}