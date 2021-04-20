//https://leetcode-cn.com/problems/house-robber-ii/submissions/

//213. 打家劫舍 II
#include <vector>
using namespace std;
class Solution {
public:
    int robRange(vector<int> &nums,int start,int end)
    {
        if (end == start)
            return nums[start];
        vector<int> dp(nums.size());
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start],nums[start + 1]);
        for (int i = start + 2;i <= end;++i)
            dp[i] = max(dp[i - 2] + nums[i],dp[i - 1]);
        return dp[end];
    }
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int result1 = robRange(nums,0,nums.size() - 2);
        int result2 = robRange(nums,1,nums.size() - 1);
        return max(result1,result2);
    }
};
