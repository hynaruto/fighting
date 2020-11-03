#include "Mine sweeping.h"
int main()
{
    int input = 0;
    int quit = 0;
    do
    {
        Menu();
        printf("请选择：");
        scanf("%d",&input);
        switch (input)
        {
            case 1:
                Game();
                break;
            case 2:
                quit = 1;
                printf("退出游戏！");
                break;
            default:
                printf("选择无效，请重新选择！");
                break;
        }
    }while (!quit);
    return 0;
}