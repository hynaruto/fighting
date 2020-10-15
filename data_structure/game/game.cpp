//
// Created by 胡杨 on 2020/10/15.
//

#include "game.h"
void Game()
{
    printf("一起玩一个猜数字游戏\n");
    srand((unsigned int)time(NULL));
    int aim = rand() % AIM + 1;
    for (; ;)
    {
        int num = 0;
        printf("请猜一个数字:\n");
        scanf("%d",&num);
        if (aim == num)
        {
            printf("恭喜");
        }else if (num < aim){
            printf("猜小了");
        } else{
            printf("猜大了");
        }

    }
}