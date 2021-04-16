//https://leetcode-cn.com/problems/russian-doll-envelopes/


//354. 俄罗斯套娃信封问题

//思路:转化为一维数组的最长递增子序列问题。难点在于怎么样对二维数组进行排序。
//对宽度进行升序，当宽度相同的时候，对高度进行降序，在高度中找到最长递增子序列。

#include <vector>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        //对宽度先进行升序排序，当宽度相同的时候对高度降序
        //问题就转化为怎么对二维数组进行排序。
        int sz = envelopes.size();
        //对二维数组进行排序
        auto cmp = [](const vector<vector<int>>& e1, const vector<vector<int>>& e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        };
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> dp(sz + 1,1);
        for (int i = 0;i < sz;++i)
        {
            for (int j = 0;j < i;++j)
            {
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        int result = 0;
        for (int i = 0;i < dp.size();++i)
            result = max(result,dp[i]);
        return result;
    }
};

int main()
{
    vector<vector<int>> v = {{5,4},{6,4},{6,7},{2,3}};
    Solution S;
    S.maxEnvelopes(v);
}