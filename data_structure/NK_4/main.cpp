class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.size()==0)
            return 0;
        int max = array[0];
        int cur = array[0];
        for (int i = 1;i < array.size();++i)
        {
            if (cur >= 0)
                cur += array[i];
            else
                cur = array[i];
            if (cur > max)
                max = cur;
        }
        return max;
    }
};