//https://leetcode-cn.com/problems/edit-distance/submissions/

//72. 编辑距离

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int Min(int a,int b,int c)
    {return min(a,min(b,c));}
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(),n = word2.size();
        //dp[i][j]:word1[0,i-1]和word[0,j-1]的最小编辑距离
        vector<vector<int>>dp(m + 1,vector<int>(n + 1,0));
        //base case
        for (int i = 1;i <= m;++i)
            dp[i][0] = i;
        for (int j = 1;j <= n;++j)
            dp[0][j] = j;
        
        for (int i = 1;i <= m;++i)
        {
            for (int j = 1;j <= n;++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];//当字符相等的时候，什么都不做，都指向下一个字符
                else
                    dp[i][j] = Min(dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    std::string s1 = "horse";
    std::string s2 = "ros";
    Solution S;
    int res = S.minDistance(s1,s2);
    cout<<res<<endl;
    return 0;
}