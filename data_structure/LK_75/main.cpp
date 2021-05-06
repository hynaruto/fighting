//https://leetcode-cn.com/problems/trapping-rain-water/

//42. 接雨水


#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        if (n <= 2)
            return 0;
        vector<int> max_left(n,0);
        vector<int> max_right(n,0);
        int m = max_right.size();
        //找到左边高度的最大值
        max_left[0] = height[0];
        for (int i = 1;i < m;++i)
            max_left[i] = max(height[i],max_left[i - 1]);
        //找到右边柱子高度的最大值
        max_right[m - 1] = height[m - 1];
        for (int i = m - 2;i >= 0;--i)
            max_right[i] = max(height[i],max_right[i + 1]);
        int sum = 0;
        for (int i = 0;i < m;++i)
        {
            int count = min(max_left[i],max_right[i]) - height[i];
            if (count > 0)
                sum += count;
        }
        return sum;
    }
};

int main()
{
    Solution S;
    std::vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    int res = S.trap(v);
    cout<<res<<endl;
    return 0;
}