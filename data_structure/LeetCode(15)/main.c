//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
#include <stdio.h>
#include <stdlib.h>
void Print(int n)
{
    int length = 0;
    int *arr = (int*)malloc(sizeof(int) * length);
    while (n)
    {
        length = length * 10 + 9;
        n--;
    }
    for (int i = 0;i < length;++i) {
        arr[i] = i + 1;
    }
    return;
}
int main()
{
    int arr[] = {0};
    int n = 0;
    puts("请输入一个整数:");
    scanf("%d",&n);
    //定义一个函数，用来实现题目要求
    Print(n);
    return 0;
}