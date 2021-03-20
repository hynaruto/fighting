//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

//思路:a^a = 0; 0^a = a; a^b^a = a^a^b = b;

#include <stdio.h>
int SingleLeNumber(int *nums,int numSize)
{
    int tmp = 0;
    for (int i = 0;i < numSize;++i)
    {
        tmp ^= nums[i];
    }
    return tmp;
}
int main()
{
    int nums[3] = {2,2,1};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int ret = SingleLeNumber(nums,numSize);
   // printf("%d\n",ret);
    return 0;
}