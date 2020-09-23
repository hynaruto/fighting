//
// Created by 胡杨 on 2020/9/23.
//

#include <stdio.h>

void menu()
{
    printf("**********************\n");
    printf("*****    1.add    ****\n");
    printf("*****    2.sub    ****\n");
    printf("*****    3.mul    ****\n");
    printf("*****    4.div    ****\n");
    printf("*****    5.exit    ***\n");
    printf("**********************\n");

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

int text()
{
    int x;
    int y;
    int input;
    int (*pfArr[5])(int , int) = { 0 ,add,sub,mul,div};
    do{
        menu();
        printf("请选择:>");
        scanf("%d",&input);
        if (input >= 1 && input <= 4)
        {
            printf("请输入两个操作数:\n");
            scanf("%d%d",&x,&y);
            int num =  pfArr[input](x,y);
            printf("%d\n",num);
        }
        else if (input == 0)
        {
            printf("退出\n");
        } else{
            printf("选择错误!\n");
        }

    }while (input);
    return 0;
}