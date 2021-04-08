//https://leetcode-cn.com/problems/combinations/submissions/

//77. 组合

#include <vector>
using namespace std;
class Solution
{
public:
    //定义一维数组,用来遍历路径
    vector<int> path;
    //定义二维数组用来存放结果
    vector<vector<int>> result;
    void backtracking(int n,int k,int StartIndex)
    {
        //递归出口:
        if (k == path.size())
        {
            result.push_back(path);
            return;
        }
        //单层循环
        for (int i = StartIndex;i <= n;++i)
        {
            //处理节点
            path.push_back(i);
            backtracking(n,k,i+1);
            //回溯
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n,k,1);
        return result;
    }
};