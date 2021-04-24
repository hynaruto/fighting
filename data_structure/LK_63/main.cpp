#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<int> dp(target + 1,0);
        dp[0] = 1;
        for (int i = 0;i <= target;++i)
        {
            for (int j = 0;j < nums.size();++j)
            {
                if (i - nums[j] >= 0 && dp[i] <= INT_MAX - dp[i - nums[j]])
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

/*
class Solution {
public:
    vector<int> path;
public:
    void backtracking(vector<int> &nums,int sum,int target,int startindex,int &count)
    {
        if (sum > target)
            return;
        //递归出口
        if (sum == target)
        {
            count++;
            return;
        }
        for (int i = startindex;i < nums.size();++i)
        {
            path.push_back(nums[i]);
            sum += nums[i];
            backtracking(nums,sum,target,i,count);
            sum -= nums[i];
            path.pop_back();
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int count = 0;
        backtracking(nums,0,target,0,count);
        return count;
    }
};
*/
int main()
{
    Solution s;
    std::vector<int> v{1,2,3};
    int result = s.combinationSum4(v,4);
    cout<<result<<endl;
}