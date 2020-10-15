#include <stdio.h>
int BinSearch (int arr[],int num ,int x)
{
    int left = 0;
    int right = num - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (x > arr[mid])
        {
            left = mid + 1;
        } else if (x < arr[mid])
        {
            right = mid - 1;
        } else{
            return mid;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {11,22,44,55,66,88,99,100,110,220,440};
    int num = (sizeof(arr)) / (sizeof(arr[0]));
    int Aim = 88;
    int index = BinSearch(arr,num,Aim);
    printf("index = %d",index);
    return 0;
}