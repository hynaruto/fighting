//剑指 Offer 57 - II. 和为s的连续正数序列

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> res;
        int i = 1,j = 1;
        int sum = 0;
        while (i <= target / 2)
        {
            if (sum < target)
            {
                //右端窗口往右移动
                sum += j;
                j++;
            }else if (sum > target)
            {
                //窗口收缩
                sum -= i;
                i++;
            }else{
                //记录数据
                vector<int> ans;
                for (int m = i;m < j;++m)
                {
                    ans.push_back(m);
                }
                res.push_back(ans);
                //窗口滑动
                sum -= i;
                i++;
            }
        }
        return res;
    }
};