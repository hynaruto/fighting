//https://leetcode-cn.com/problems/longest-palindromic-subsequence/submissions/

//516. 最长回文子序列

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        //dp[i][j]的含义就是字符串s[i,j]内的最长回文子序列
        vector<vector<int>>dp(n,vector<int>(n,0));
        for (int i = 0;i < n;++i)
            dp[i][i] = 1;//base case;
        for (int i = n - 2;i >= 0;--i)
        {
            for (int j = i + 1;j < n;++j)
            {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};

int main()
{
    const char *s = "bbbab";
    Solution S;
    int result = S.longestPalindromeSubseq(s);
    cout<<result<<endl;
    return 0;
}