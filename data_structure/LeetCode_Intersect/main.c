//给定两个数组，编写一个函数来计算它们的交集。

//例子1:
//输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2,2]

//例子2:
//输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[4,9]

//说明：
//输出结果中每个元素出现的次数，应与元素在两个数组中出现次数的最小值一致。
//我们可以不考虑输出结果的顺序。


//思路:先给数组排序，利用双指针同时指向两个数组的首位，如果相等，则把相等的值赋给数组，如果不想等，值大的不动，小的移动

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a,const void* b)
{return *(int*)a - *(int*)b;}

int* intersect(int *nums1,int *nums2,int numsSize1,int numsSize2)
{
    qsort(nums1,numsSize1,sizeof(int),cmp);
    qsort(nums2,numsSize2,sizeof(int),cmp);

    int *arr = malloc(sizeof(int) * fmin(numsSize1,numsSize2));

    int k = 0;
    int strat1 = 0,strat2 = 0;
    while (strat1 < numsSize1 && strat2 < numsSize2)
    {
        if (nums1[strat1] < nums2[strat2])
        {
            strat1++;
        } else if (nums1[strat1] > nums2[strat2])
        {
            strat2++;
        }else{
            arr[k++] = nums1[strat1];
            strat1++,strat2++;
        }
    }
    return arr;
}

int main()
{
    int nums1[] = {4,9,5};
    int nums2[] = {9,4,9,8,4};
    int numSize1 = sizeof(nums1) / sizeof(nums1[0]);
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    intersect(nums1,nums2,numSize1,numsSize2);
    return 0;
}