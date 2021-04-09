//https://leetcode-cn.com/problems/combination-sum/submissions/

//39. 组合总和

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtrack(vector<int> &candidates,int sum,int target,int StartIndex)
    {
        //递归出口
        if (sum > target)
            return;
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        //单层循环
        for (int i = StartIndex; i < candidates.size();++i)
        {
            path.push_back(candidates[i]);
            sum += candidates[i];
            //因为数组元素可以重复
            backtrack(candidates,sum,target,i);
            //回溯
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        backtrack(candidates,0,target,0);
        return result;
    }
};