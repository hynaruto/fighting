//利用二分查找，找到数组里面最小的数字
#include <stdio.h>
int BlnSearch(int arr[],int size)
{
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        if (arr[left] == arr[right])
        {
            left++;
            continue;
        }
        int mid = (left + right) / 2;
        if (arr[mid] > arr[right])
        {
            left = mid + 1;
        } else{
            right = mid;
        }
    }
    int result = printf("%d",arr[left]);
    return result;
}
int main()
{
    int arr[] = {3,4,5,6,1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    BlnSearch(arr,size);
    return 0;
}