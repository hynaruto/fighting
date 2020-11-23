//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
#include <stdio.h>
int MajorityElement(int arr[],int size)
{
    int count = 0,res = 0;
    for (int i = 0;i < size;++i)
    {
        if (count == 0)
        {
            res = arr[i];
            count++;
        } else if (res == arr[i])
        {
            count++;
        } else{
            count--;
        }
    }
    return res;
}
int main()
{
    int arr[] = {1,22,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,5,5,6,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = MajorityElement(arr,size);
    printf("%d\n",result);
    return 0;
}