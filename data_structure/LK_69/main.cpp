//https://leetcode-cn.com/problems/sum-of-square-numbers/submissions/

//633. 平方数之和


#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c)
    {
        //思路:双指针
        long left = 0,right = (int)sqrt(c);
        while (left <= right)
        {
            long sum = left * left + right * right;
            if (sum == c)
                return true;
            else if (sum > c)
                --right;
            else
                ++left;
        }
        return false;
    }
};

int main()
{
    Solution S;
    S.judgeSquareSum(5);
    return 0;
}