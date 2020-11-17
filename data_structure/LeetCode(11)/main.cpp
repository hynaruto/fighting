//写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

#include <stdio.h>
int main()
{
    int a = 1;
    int b = 2;
    while (a != 0)
    {
        int tmp = a ^ b;
        //循环出口
        a = (a & b) << 1;
        b = tmp;
    }
    printf("%d",b);
    return 0;
}