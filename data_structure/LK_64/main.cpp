//https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/

//剑指 Offer 42. 连续子数组的最大和


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 0)
             return 0;
        //dp[i]的定义:以nums[i]结尾的最大连续子数组之和为dp[i]
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0]; //base case
        for (int i = 1;i < nums.size();++i)
            dp[i] = max(nums[i],dp[i - 1] + nums[i]);
        //遍历dp数组，找到最大值
        int res = INT_MIN;
        for (int i = 0;i < dp.size();++i)
            res = max(res,dp[i]);
        return res;
    }
};
int main()
{
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int res = s.maxSubArray(nums);
    cout<<res<<endl;
    return 0;
}