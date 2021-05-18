//22. 括号生成

//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。


#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string>res;
public:
    void dfs(string s,int left,int right)
    {
        if (!left && !right)
            res.push_back(s);
        if (left > 0)
            dfs(s + '(',left - 1,right);
        if (right > left)
            dfs(s + ')',left,right - 1);
    }
public:
    vector<string> generateParenthesis(int n)
    {
        string s = "";
        dfs(s,n,n);
        return res;
    }
};

int main()
{
    Solution S;
    int n = 2;
    vector<string>res;
    res = S.generateParenthesis(n);
    for (const auto & re : res)
        cout<<"["<<re<<",";
    cout<<endl;
    return 0;
}