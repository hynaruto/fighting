//https://leetcode-cn.com/problems/coin-change/

//322. 零钱兑换


//给定不同面额的硬币 coins 和一个总金额 amount。
// 编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
// 如果没有任何一种硬币组合能组成总金额，返回 -1。
//你可以认为每种硬币的数量是无限的。

#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1,INT_MAX);
        dp[0] = 0;
        for (int i = 0;i < coins.size();++i) //{1,2,5}
        {
            for (int j = coins[i];j <= amount;++j)
            {
                if (dp[j - coins[i]] != INT_MAX)
                    dp[j] = min(dp[j - coins[i]] + 1,dp[j]);
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
int main()
{
    std::vector<int> v = {1,2,5};
    Solution S;
    S.coinChange(v,5);
}