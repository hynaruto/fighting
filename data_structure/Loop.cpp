#include <stdio.h>
int main()
{
    int a ,b;
    printf("输入整数:");
    scanf("%d",&a);
    for (b = 1;b <= a;b++){
        printf("%d",b % 10);
    }
    return 0;
}