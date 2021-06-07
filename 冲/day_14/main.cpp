#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int>days{31,28,31,30,31,30,31,31,30,31,30,31};
bool IsLeapYear(int &year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int fun(int mon,int day)
{
    int date = 0;
    for (int i = 0;i < mon - 1;++i)
        date += days[i];
    date += day;
    return date;
}
int main()
{
    int year,mon,day;
    int date = 0;
    while (cin >> year >> mon >> day)
    {
        if (IsLeapYear(year))
        {
            if (mon > 2)
                date = fun(mon,day) + 1;
            else
                date = fun(mon,day);
        }
        else
            date = fun(mon,day);
        cout<<date<<endl;
    }
    return 0;
}

/*
class Solution
{
public:
    int dfs(const int &n,vector<int> &nums,int index,int sum,int mul)
    {
        int count = 0;
        for (int i = index;i < n;++i)
        {
            sum += nums[i];
            mul *= nums[i];
            if (sum > mul)
                count += 1 + dfs(n,nums,i + 1,sum,mul);
            else if (nums[i] == 1)
                count += dfs(n,nums,i + 1,sum,mul);
            else
                break;
            sum -= nums[i];
            mul /= nums[i];
            while (i < n - 1 && nums[i] == nums[i + 1])
                ++i;
        }
        return count;
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<int> nums(n,0);
    for (int i = 0; i < n;++i)
        cin>>nums[i];
    sort(nums.begin(),nums.end());
    Solution S;
    cout<<S.dfs(n,nums,0,0,1);
    return 0;
}
*/