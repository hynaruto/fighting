//https://leetcode-cn.com/problems/unique-paths/

//62. 不同路径
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        //dp[i][j]:从(0,0)到(i,j)有多少条不同路径
        vector<vector<int>>dp(m,vector<int>(n,0));
        //base case
        for (int i = 0;i < m;++i)
            dp[i][0] = 1;
        for (int j = 0;j < n;++j)
            dp[0][j] = 1;
        for (int i = 1;i < m;++i)
        {
            for (int j = 1;j < n;++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution S;
    int res = S.uniquePaths(3,2);
    cout<<res<<endl;
}