//47. 全排列 II

//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。



#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
public:
    void backtracking(vector<int> &nums,vector<bool>used)
    {
        //递归出口
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0;i < nums.size();++i)
        {
            if (!used[i])
            {
                if (i >= 1 && nums[i] == nums[i - 1] && !used[i - 1])//剪枝
                    continue;
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums,used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<bool>used(nums.size(),0);
        backtracking(nums, used);
        return res;
    }
};