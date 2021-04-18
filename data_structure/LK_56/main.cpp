//https://leetcode-cn.com/problems/product-of-array-except-self/submissions/

//238. 除自身以外数组的乘积

//思路:左右乘积列表

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int sz = nums.size();
        vector<int> left(sz,0);
        vector<int> right(sz,0);
        vector<int> result(sz);
        left[0] = 1;
        for (int i = 1;i < sz;++i)
            left[i] = nums[i - 1] * left[i - 1];
        right[sz - 1] = 1;
        for (int i = sz - 2;i >= 0;--i)
            right[i] = nums[i + 1] * right[i + 1];
        for (int i = 0;i < sz;++i)
            result[i] = left[i] * right[i];
        return result;
    }
};

int main()
{
    std::vector<int> v{1,2,3,4};
    Solution S;
    S.productExceptSelf(v);
}