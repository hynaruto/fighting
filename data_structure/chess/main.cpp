#include "chess.h"
int main()
{
    int select = 0;
    int quit = 0;
    while(!quit)
    {
        //打印菜单；
        ShowMenu();
        scanf("%d",&select);
        switch (select)
        {
            case 1:
                Game();
                break;
            case 2:
                quit = 1;
                printf("退出游戏！");
                break;
            default:
                printf("选择有误，请重新选择！");
        }
    }
    return 0;
}