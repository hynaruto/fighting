#include "DCList.h"
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
    printf("*****15.Destroy***********************16.RemoveAll********************\n");
    printf("**************************************0.Exit**************************\n");
    printf("**********************************************************************\n");
    printf("Please select:\n");
}

enum
{
    Exit,Push_Back,Pop_Back,Push_Front,Pop_Front,Show_List,Length,Sort,Insert_val,Delect_val,\
    Insert_pos,Delect_pos,Find,Reverse,Clear,Destory,RemoveAll
};

int main()
{
    DCList mylist,postion;
    DCListInit(&mylist);
    Elempty key,item,pos;
    int select = 1;
    while (select)
    {
        Menu();
        scanf("%d",&select);
        switch (select)
        {
            case Exit:
                select = 0;
                printf("exit successful!\n");
                break;
            case Push_Back:
                printf("please enter items(end by -1):\n");
                while ((scanf("%d",&item)) , item != -1)
                {
                    DCListPushBack(&mylist,item);
                }
                break;
            case Pop_Back:
                DCListPopBack(&mylist);
                break;
            case Push_Front:
                printf("please enter items(end by -1):\n");
                while ((scanf("%d",&item)) , item != -1)
                {
                    DCListPushFront(&mylist,item);
                }
                break;
            case Pop_Front:
                DCListPopFront(&mylist);
                break;
            case Show_List:
                DCListShow(&mylist);
                break;
            case Length:
                DCListlength(&mylist);
                break;
            case Sort:
                DCListSort(&mylist);
                break;
            case Insert_val:
                printf("please enter items(end by -1):\n");
                while ((scanf("%d",&item)) , item != -1)
                {
                    DCListInsert_val(&mylist,item);
                }
                break;
            case Delect_val:
                printf("please enter key:\n");
                scanf("%d",&key);
                DCListDelect_val(&mylist,key);
                break;
            case Insert_pos:
                printf("please enter the pos %d and enter the item %d:\n",pos,item);
                scanf("%d",&pos);
                scanf("%d",&item);
                DCLIstInsert_pos(&mylist,item,pos);
                break;
            case Delect_pos:
                printf("please enter the pos:\n");
                scanf("%d",&pos);
                DCListDelect_pos(&mylist,pos);
                break;
            case Find:
                printf("please entern the key:\n");
                scanf("%d",&key);
                DCListFind(&mylist,key);
                break;
            case Reverse:
                DCListReverse(&mylist);
                break;
            case Clear:
                DCListClear(&mylist);
                break;
            case Destory:
                DCListDestory(&mylist);
                break;
            case RemoveAll:
                printf("please enter the item:\n");
                scanf("%d",&item);
                DCLIstRemoveAll(&mylist,item);
                break;
            default:
                printf("select error! please select again\n");
                break;
        }

    }
    return 0;
}