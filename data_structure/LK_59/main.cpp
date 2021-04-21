//https://leetcode-cn.com/problems/kth-largest-element-in-an-array/submissions/

//215. 数组中的第K个最大元素

#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector <int>, greater <int>> pq;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};