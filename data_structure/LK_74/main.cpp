//https://leetcode-cn.com/problems/2-keys-keyboard/

//650. 只有两个键的键盘

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSteps(int n)
    {
        vector<int> dp(n + 1,0);
        for (int i = 2;i <= n;++i)
        {
            dp[i] = i;
            for(int j = 2;j <= n;++j)
            {
                if (i % j == 0)
                    dp[i] = dp[j] + dp[i / j];
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution S;
    int res = S.minSteps(6);
    cout<<res<<endl;
    return 0;
}