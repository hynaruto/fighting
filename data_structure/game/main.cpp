#include "game.h"
void Menu()
{
    printf("*********************\n");
    printf("*******1.Play********\n");
    printf("*******2.Exit********\n");
    printf("*********************\n");
}


int main()
{
    //用户登陆
    char name[64];
    char Password[64];
    int times = 3;
    printf("请输入用户名：\n");
    scanf("%s",name);
    printf("请输入登陆密码:\n");
    scanf("%s",Password);
    while (1)
    {
        if ((strcmp(name, NAME) == 0) && (strcmp(Password, PASSWD) == 0)) {
            break;
        } else {
            printf("用户名或密码错误！\n");
            times--;
            printf("你还有%d次机会\n",times);
            if (times == 0)
            {
                printf("请在%d秒后重试!\n",3);
                Sleep(3000);
                times = 3;
            }
        }
    }
    if (times > 0)
        printf("登陆成功！\n");


    int Select = 0;
    int quit = 0;
    printf("请选则:");
    scanf("%d", &Select);
    while (!quit) {
        switch (Select) {
            case 1 :
                //玩游戏
                Game();
                printf("牛逼，要不要再来一次？\n");
                break;
            case 2 :
                //退出
                quit = 1;
                puts("游戏结束！\n");
                break;
            default:
                puts("输入错误，请重新输入：\n");
                break;

        }
    }


    return 0;
}