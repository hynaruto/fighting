#include "Contact.h"

void menu()
{
    printf("*****************************\n");
    printf("*******1.Add*****************\n");
    printf("*******2.Del*****************\n");
    printf("*******3.Search**************\n");
    printf("*******4.Modify**************\n");
    printf("*******5.Show****************\n");
    printf("*******6.Sort****************\n");
    printf("*******0.Exit****************\n");
    printf("*****************************\n");
}

int main()
{
    int input = 0;

    //创建通讯录
    struct Contact con; //con就是通讯录，里面有1000个元素和size；

    //初始化通讯录
    InitContact(&con);

    do
    {
        menu();
        printf("请选择:\n");
        scanf("%d",&input);
        switch (input)
        {
            case ADD:
                AddContact(&con);
                break;
            case DEL:
                DelContact(&con);
                break;
            case SEARCH:
                SearchContact(&con);
                break;
            case MODIFY:
                ModifyContact(&con);
                break;
            case SHOW:
                ShowContact(&con);
                break;
            case SORT:
                SortContact(&con);
                break;
            case EXIT:
                printf("退出通讯录!\n");
                break;
            default:
                puts("选择错误！\n");
        }
    }while (input != 0);
    return 0;
}