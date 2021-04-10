//https://leetcode-cn.com/problems/combination-sum-ii/submissions/

//40. 组合总和 II

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    //搜索路径
    vector<int> path;
    //存放结果
    vector<vector<int>> result;
public:
    void backtracking(vector<int> &candidates,int sum,int target,int StartIndex,vector<bool> used)
    {
        //递归出口
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        //单次循环
        for (int i = 0;i < candidates.size() && sum + candidates[i] <= target;++i)
        {
            //判断是否使用重复元素
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i] == false)
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates,sum,target,i + 1,used);
            used[i] = false;
            //回溯
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<bool> used(candidates.size(),false);
        //排序，让相同元素在一起
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,0,target,0,used);
        return result;
    }
};



/*
int main()
{
    vector<int> arr{10,1,2,7,6,1,5};
    int target = 8;
    Solution S;
    S.combinationSum2(arr, 8);
    return 0;
}
*/