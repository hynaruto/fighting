//https://leetcode-cn.com/problems/palindrome-partitioning/

//131. 分割回文串


#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    static bool isPailinddrome(const string &s,int start,int end)
    {
        for (int i = start,j = end;i < j;++i,--j)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
public:
    void backtracking(const string &s,int StartIndex)
    {
        if (StartIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
        //单层切割
        for (int i = StartIndex;i <= s.size();++i)
        {
            //如果是回文串，则push
            //[StartIndex,i]就是切割的回文子串
            if (isPailinddrome(s,StartIndex,i))
            {
                //获取回文子串
                string str = s.substr(StartIndex,i - StartIndex + 1);
                path.push_back(str);
            }else{
                //跳过本次循环，进行下一次切割
                continue;
            }
            backtracking(s,i+1);
            //回溯
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s,0);
        return result;
    }
private:
    //搜索路径
    vector<string> path;
    //存放结果
    vector<vector<string>> result;
};

int main()
{
    Solution test;
    char s[] = "aab";
    test.partition(s);
}