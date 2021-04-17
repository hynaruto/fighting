//https://leetcode-cn.com/problems/house-robber/submissions/

//198. 打家劫舍



//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。


//输入：[1,2,3,1]
//输出：4
//解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//偷窃到的最高金额 = 1 + 3 = 4 。

#include <vector>
using namespace std;

class Solution{
public:
    int rob(vector<int> &nums)
    {
        //如果你都没有房子，那你偷个屁啊
        if (nums.size() == 0)
            return 0;
        //你只有一个房子，那你还有的选？
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size());
        dp[0] = 1;
        //这个语句就是说，你只有2间房子，为了不触发警报，你只能在这两个房子中选一个钱最多的来偷。
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2;i < nums.size();++i)
        {
            //如果考虑偷i间，那么剩下的只能从i-2开始找最值钱的，再加上nums[i]，就是你能偷到的最多的钱
            //如果不考虑第i间，那么就从i - 1间开始
            dp[i] = max(dp[i - 2] + nums[i],dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};

int main()
{
    std::vector<int> v{1,2,3,1};
    Solution S;
    S.rob(v);
    return 0;
}