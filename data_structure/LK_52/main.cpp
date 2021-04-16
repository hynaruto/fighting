//https://leetcode-cn.com/problems/target-sum/submissions/

//494. 目标和

#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (target > sum || (target + sum) % 2 == 1)
            return 0;
        int bagsize = (sum + target) / 2;
        vector<int> dp(bagsize + 1,0);
        dp[0] = 1;
        for (int num : nums)
        {
            for (int j = bagsize;j >= num;--j)
                dp[j] += dp[j - num];
        }
        return dp[bagsize];
    }
};

int main()
{
    std::vector<int> v{1,1,1,1,1};
    Solution S;
    S.findTargetSumWays(v,5);
    return 0;
}
