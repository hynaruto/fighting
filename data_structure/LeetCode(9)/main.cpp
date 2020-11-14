//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
#include <cstdlib>
int* exchange(int* nums, int numsSize, int* returnSize)
{
    int i ,count = 0;
    int* res = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    for (i = 0;i < numsSize;++i)
    {
        if (nums[i] % 2 == 1)
        {
            res[count++] = nums[i];
        }
    }
    for (i = 0;i < numsSize;++i)
    {
        if (nums[i] % 2 == 0)
        {
            res[count++] = nums[i];
        }
    }
    return res;
}