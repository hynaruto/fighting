//https://leetcode-cn.com/problems/longest-common-subsequence/

//1143. 最长公共子序列

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(),n = text2.size();
        //dp[i][j]表示的是text[0,i - 1]和text2[0,j - 1]，它们最长公共子序列的长度为dp[i][j]
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));//base case;
        for (int i = 1;i <= m;++i)
        {
            for (int j = 1;j <= n;++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    std::string s1 = "abcde";
    std::string s2 = "ace";
    Solution S;
    int res = S.longestCommonSubsequence(s1,s2);
    cout<<res<<endl;
}