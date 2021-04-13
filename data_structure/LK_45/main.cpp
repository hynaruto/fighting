//https://leetcode-cn.com/problems/3sum/

//15. 三数之和
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> nSumTarget(vector<int> &nums,int n,int start,int target)
    {
        vector<vector<int>> result;
        int sz = nums.size();
        //n < 2 或者sz < n 直接返回
        if (n < 2 || sz < n)
            return result;
        //所有问题回归到n==2
        if (n == 2)
        {
            int low = start,high = sz - 1;
            while (low < high)
            {
                int sum = nums[low] + nums[high];
                int left = nums[low],right = nums[high];
                if (sum < target)
                {
                    while (low < high && nums[low] == left)
                        low++;
                }else if(sum > target)
                {
                    while (low < high && nums[high] ==right)
                        high--;
                }else{
                    result.push_back({left,right});
                    while(low < high && nums[low] == left)
                        low++;
                    while (low < high && nums[high] == right)
                        high--;
                }
            }
        }else{
            //如果n > 2，那么使用递归
            for (int i = start;i < sz;++i)
            {
                vector<vector<int>> sub = nSumTarget(nums,n - 1,i + 1,target - nums[i]);
                for (vector<int>& arr : sub)
                {
                    arr.push_back(nums[i]);
                    result.push_back(arr);
                }
                //去重复
                while (i < sz - 1 && nums[i] == nums[i + 1])
                    i++;
            }
        }
        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        //对数组进行排序
        sort(nums.begin(),nums.end());
        return nSumTarget(nums,3,0,0);
    }
};