//https://leetcode-cn.com/problems/longest-increasing-subsequence/submissions/

//300. 最长递增子序列

//时间复杂符:O(N ^ 2)
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        //base case
        vector<int> dp(nums.size() + 1, 1);
        for (int i = 0;i < nums.size() - 1;++i)
        {
            for (int j = 0;j < i;++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        int result = 0;
        for (int i = 0;i < dp.size();++i)
            result = max(result,dp[i]);
        return result;
    }
};
int main()
{
    std::vector<int> v{10,9,2,5,3,7,101,18};
    Solution S;
    S.lengthOfLIS(v);
    return 0;
}