//https://leetcode-cn.com/problems/remove-element/

int removeElement(int* nums, int numsSize, int val)
{
    int size = 0;
    for (int i = 0;i < numsSize;++i)
    {
        if (nums[i] != val)
        {
            nums[size] = nums[i];
            size++;
        }
    }
    return size;
}