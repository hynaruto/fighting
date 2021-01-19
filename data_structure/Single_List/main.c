#include "Single_List.h"
void Menu()
{
    printf("**********************************************************************\n");
    printf("*****1.Push_Back**********************2.Pop_Back**********************\n");
    printf("*****3.Push_Front*********************4.Pop_Front*********************\n");
    printf("*****5.Show_List**********************6.Length************************\n");
    printf("*****7.Sort***************************8.Insert_val********************\n");
    printf("*****9.Delect_val*********************10.Insert_pos*******************\n");
    printf("*****11.Delect_pos********************12.Find*************************\n");
    printf("*****13.Reverse***********************14.Clear************************\n");
    printf("*****15.Destroy***********************0.Exit**************************\n");
    printf("**********************************************************************\n");
    printf("Please select:\n");
}

enum
{
    Exit,Push_Back,Pop_Back,Push_Front,Pop_Front,Show_List,Length,Sort,Insert_val,Delect_val,\
    Insert_pos,Delect_pos,Find,Reverse,Clear,Destory
};
int main()
{
    Slist mylist;
    SlistNode *p;
    //初始化单链表
    Init_List(&mylist);
    ElemType key,item,pos;
    int select = 1;
    while (select)
    {
        Menu();
        scanf("%d",&select);
        switch (select)
        {
            case Push_Back:
                printf("Please enter the data(end biy -1):\n");
                while ((scanf("%d",&item)) && item != -1)
                {
                    SlistPushBack(&mylist,item);
                }
                break;
            case Pop_Back:
                SlistPopBack(&mylist);
                break;
            case Push_Front:
                printf("please enter item:\n");
                while ((scanf("%d",&item)) && item != -1)
                {
                    SlistPushFront(&mylist,item);
                }
                break;
            case Pop_Front:
                SlistPopFront(&mylist);
                break;
            case Show_List:
                SlistShow(&mylist);
                break;
            case Length:
                SlistLength(&mylist);
                break;
            case Sort:
                SlistSort(&mylist);
                break;
            case Insert_val:
                printf("pleasse enter item:\n");
                scanf("%d",&item);
                SlistInsert_val(&mylist,item);
                break;
            case Delect_val:
                printf("please enter the key:\n");
                scanf("%d",&key);
                SlistDelect_val(&mylist,key);
                break;
            case Insert_pos:
                //无
                break;
            case Delect_pos:
                //无
                break;
            case Find:
                SlistFind(&mylist,key);
                break;
            case Reverse:
                SlistReverse(&mylist);
                break;
            case Clear:
                SlistClear(&mylist);
                break;
            case Destory:
                SlistDestory(&mylist);
                break;
            case Exit:
                select = 0;
                printf("Exit successful!\n");
                break;
            default:
                printf("select error!\n");
                break;
        }

    }
    return 0;
}