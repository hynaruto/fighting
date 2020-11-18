//请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。
#include <stdio.h>
int FindOneNum(unsigned int a)
{
    int count = 0;
    while (a != 0)
    {
        a &= a - 1;
        count++;
    }
    return count;
}
int main()
{
    int a = 0;
    puts("请输入整数a:");
    scanf("%d",&a);
    int result = FindOneNum(a);
    printf("%d\n",result);
    return 0;
}