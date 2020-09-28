#include <stdio.h>
void menu()
{
    printf("*****    1.add    ****\n");
    printf("*****    2.sub    ****\n");
    printf("*****    3.mul    ****\n");
    printf("*****    4.div    ****\n");
    printf("*****    5.exit    ****\n");

}
int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}

int main()
{
    int x;
    int y;
    int input = 0;
    do{
        menu();
        printf("请选择:\n");
        scanf("%d",&input);
        printf("请输入两个操作数:>");
        scanf("%d%d",&x,&y);
        switch (input)
        {
            case 1:
                printf("请输入两个操作数:>");
                scanf("%d%d",&x,&y);
                printf("%d\n",add(x,y));
                break;
            case 2:
                printf("请输入两个操作数:>");
                scanf("%d%d",&x,&y);
                printf("%d\n",sub(x,y));;
                break;
            case 3:
                printf("请输入两个操作数:>");
                scanf("%d%d",&x,&y);
                printf("%d\n",mul(x,y));
                break;
            case 4:
                printf("请输入两个操作数:>");
                scanf("%d%d",&x,&y);
                printf("%d\n",div(x,y));
                break;
            case 5:
                printf("退出\n");
            default:
                printf("选择错误！\n");

        }
    }while (input);


    return 0;
}