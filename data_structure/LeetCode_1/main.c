//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2ba4i/

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。


//双指针
void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void moveZeroes(int* nums, int numsSize)
{
    int left = 0,right = 0;
    while (right < numsSize)
    {
        if (nums[right] != 0)
        {
            Swap(nums + left,nums + right);
            left++;
        }
        right++;
    }
}