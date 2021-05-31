#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string Fun(vector<string> &nums)
    {
        if (IsLengths(nums) && Is_Lex_Graphically(nums))
            cout<<"both";
        else if (IsLengths(nums) && !Is_Lex_Graphically(nums))
            cout<<"lengths";
        else if (!IsLengths(nums) && Is_Lex_Graphically(nums))
            cout<<"lexicographically";
        else
            cout<<"none";
        return "none";
    }

protected:
    static bool Is_Lex_Graphically(vector<string> &nums)
    {
        //根据首字母大小
        for (int i = 0;i < nums.size() - 1;++i)
        {
            if (nums[i].compare(nums[i + 1]) > 0)
                return false;
        }
        return true;
    }
    static bool IsLengths(vector<string> &nums)
    {
        //根据长度排列
        for (int i = 0;i < nums.size() - 1;++i)
        {
            if (nums[i].size() > nums[i + 1].size())
                return false;
        }
        return true;
    }
};
int main()
{
    int n = 0;
    string str;
    cin >> n;
    vector<string> nums(n);
    for (int i = 0;i < nums.size();++i)
        cin>>nums[i];
    Solution S;
    S.Fun(nums);
    return 0;
}