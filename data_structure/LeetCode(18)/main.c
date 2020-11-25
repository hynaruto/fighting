//得到一个排序数组中出数字出现的次数
#include <stdio.h>
int MidSearch(int* arr,int size,int target)
{
    int left = 0;
    int right = size - 1;
    int count = 0;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (arr[mid] == target)
        {
            for (int i = mid - 1;i < size && arr[i] == target;++i)
            {
                count++;
            }
            for (int i = mid;i < size && arr[i] == target;++i)
            {
                count++;
            }
            break;
        } else if (arr[mid] < target)
        {
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return count;
}
int main()
{
    int target = 4;
    int arr[] = {1,2,3,3,3,4,4,4,5,5,5,6,6,7,7,8,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = MidSearch(arr,size,target);
    printf("%d",result);
    return 0;
}