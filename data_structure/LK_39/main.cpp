//https://leetcode-cn.com/problems/permutations/submissions/

//46. 全排列

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
public:
    void backtrack(vector<int> &nums,vector<bool> Int)
    {
        //递归出口
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        //单层递归
        for (int i = 0;i < nums.size();++i)
        {
            //如果path里面的元素有重复，则跳过本次循环
            if (Int[i])
                continue;
            Int[i] = true;
            path.push_back(nums[i]);
            backtrack(nums,Int);
            //回溯
            path.pop_back();
            Int[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<bool> Int(nums.size(),false);
        backtrack(nums,Int);
        return result;
    }
};
