//
// Created by 胡杨 on 2020/9/23.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}
float cmp_float(const void* e1,const void* e2)
{
    return ((int)(*(float*)e1 - *(float*)e2));
}
void text1()
{
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr,sz, sizeof(arr[0]),cmp_int);
    int i = 0;
    for (i = 0;i < sz;i++)
    {
        printf("%d",arr[i]);
    }
}
void text2()
{
    float f[] = {9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0};
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f,sz, sizeof(f[0]),cmp_int);
    int j = 0;
    for (j = 0;j < sz;j++)
    {
        printf("%f",f[j]);
    }
}
int test()
{
    //text1();
    text2();
    return 0;


}