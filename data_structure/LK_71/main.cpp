//https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

//1312. 让字符串成为回文串的最少插入次数

#include <vector>
#include <string>
using namespace std;
//状态压缩
class Solution {
public:
    int minInsertions(string s)
    {
        int n = s.size();
        vector<int>dp(n,0);
        for (int i = n - 2;i >= 0;--i)
        {
            int pre = 0;
            for (int j = i + 1;j < n;++j)
            {
                int tmp = dp[j];
                if (s[i] == s[j])
                    //dp[i][j] = dp[i + 1][j - 1];
                    dp[j] = pre;
                else
                    //dp[i][j] = min(dp[i + 1][j],dp[i][j - 1]);
                    dp[j] = min(dp[j],dp[j - 1]) + 1;
                pre = tmp;
            }
        }
        return dp[n - 1];
    }
};







/*
//普通版本
class Solution {
public:
    int minInsertions(string s)
    {
        int n = s.size();
        //dp[i][j]表示已s[i,j]结尾的最小插入次数为dp[i][j],才能构成回文;
        //base case:dp[i][j] = 0;
        vector<vector<int>>dp(n,vector<int>(n,0));
        for (int i = n - 2;i >= 0;--i)
        {
            for (int j = i + 1;j < n;++j)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = min(dp[i + 1][j],dp[i][j - 1]) + 1;
            }
        }
        return dp[0][n - 1];
    }
};
*/

int main()
{
    std::string s = "mbadm";
    Solution S;
    S.minInsertions(s);
    return 0;
}