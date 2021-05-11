
//剑指 Offer 38. 字符串的排列
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> res;
    string path;
public:
    void backtrackint(string s,vector<bool> used)
    {
        //递归出口
        if (s.size() == path.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0;i < s.size();++i)
        {
            if (!used[i])
            {
                if (i >= 1 && s[i] == s[i - 1] && !used[i - 1])
                    continue;
                path.push_back(s[i]);
                used[i] = true;
                //回溯
                backtrackint(s,used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<string> permutation(string s)
    {
        string path = "";
        vector<bool> used(s.size(),0);
        sort(s.begin(),s.end());
        backtrackint(s,used);
        return res;
    }
};
int main()
{
    string s = "abc";
    Solution S;
    vector<string> res;
    res = S.permutation(s);
    for (int i = 0; i < res.size();++i)
        cout<<res[i]<<endl;
    return 0;
}

