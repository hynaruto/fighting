//416. 分割等和子集


#include <iostream>
#include <vector>
using namespace std;


//状态压缩
class Solution {
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int c : nums)
            sum += c;
        if (sum & 1)
            return false;
        vector<bool> dp(sum / 2 + 1,0);
        //base case;
        dp[0] = true;
        for (int i = 0;i < nums.size();++i)
        {
            for (int j = sum / 2 ;j >= 0;--j)
            {
                if (j >= nums[i - 1])
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum / 2];
    }
};


//普通版本
/*
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (int c : nums)
            sum += c;
        if (sum & 1)
            return false;
        //问题转化为背包问题
        //有一个重量为sum/2的背包和nums.size()个物品,每个物品的重量的nums[i]
        //判断有没有一种装法，能够恰好装满背包
        vector<vector<bool >> dp(nums.size() + 1,vector<bool>(sum / 2 + 1,0));
        //base case
        for (int i = 0;i <= nums.size();++i)
            dp[i][0] = true;
        for (int i = 1;i <= nums.size();++i)
        {
            for (int j = 1;j <= sum / 2;++j)
            {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j]|| dp[i - 1][j - nums[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[nums.size()][sum / 2];
    }
};
*/