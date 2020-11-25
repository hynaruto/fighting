//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
#include <stdio.h>
#include <stdlib.h>
int comp(const void* x,const void* y)
{
    return *(int*)x - *(int*)y;
}
int main()
{
    int arr[] = {1,2,8,9,5,12,0,7,3,4,5,6};
    int k = 0;
    puts("请输入一个整数：");
    scanf("%d",&k);
    int* ret = (int*)malloc(sizeof(int) * k);
    int size = sizeof(arr) / sizeof(arr[0]);
    qsort(arr,size,sizeof(int),comp);
    for (int i = 0;i < k;++i)
    {
        ret[i] = arr[i];
    }
    for (int i = 0;i < k;++i)
    {
        printf("%d ",ret[i]);
    }
    return 0;
}