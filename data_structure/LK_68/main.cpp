//https://leetcode-cn.com/problems/longest-palindromic-substring/submissions/
//5. 最长回文子串

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int begin = 0,end = 0,length = 0;
        //从左到右，从下到上遍历
        for (int i = n - 1;i >= 0;--i)
        {
            for (int j = i;j < n;++j)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else if (dp[i + 1][j - 1] == true)
                        dp[i][j] = true;
                }
                if (dp[i][j] && j - i + 1 > length)
                {
                    length = j - i + 1;
                    begin = i,end = j;
                }
            }
        }
        return s.substr(begin,end - begin + 1);
    }
};
int main()
{
    std::string s = "babad";
    Solution S;
    S.longestPalindrome(s);
    return 0;
}