#include "SeqList.h"
void Menu()
{
    printf("******************************************************************************\n");
    printf("****1.Push_back*****************************2.Push_front**********************\n");
    printf("****3.Pop_back******************************4.Pop_front***********************\n");
    printf("****5.Show_List*****************************6.List_length*********************\n");
    printf("****7.List_capacity*************************8.Insert_pos**********************\n");
    printf("****9.Delete_val****************************10.Delete_pos*********************\n");
    printf("****11.Find*********************************12.Sort***************************\n");
    printf("****13.Reverse******************************14.Remove_Al**********************\n");
    printf("****15.Clear********************************16.Destory_List*******************\n");
    printf("*****************************0.Exit****************************************\n");
    printf("******************************************************************************\n");
    printf("Please select:\n");
}


enum
{
    Exit,Push_back,Push_front,Pop_back,Pop_front,Show_List,List_length,List_capacity,Insert_pos,\
    Delete_pos,Find,Sort,Reverse,Remove_All,Clear,Destory_List,Find_binary
};
int main()
{
    //定义顺序表
    SeqList my_list;
    //初始化顺序表
    InitSeqList(&my_list);
    //类型
    ELEMTYPE item,key,pos;
    int select = 1;
    while (select)
    {
        Menu();
        scanf("%d",&select);
        switch (select)
        {
            case Push_back:
                printf("Please select data:(end by -1)\n");
                while(scanf("%d", &item), item!=-1)//插入元素，以-1结尾
                {
                    SeqListPush_back(&my_list,item);
                }
                break;
            case Push_front:
                printf("Please select data:(end by -1)\n");
                while(scanf("%d", &item), item!=-1)//插入元素，以-1结尾
                {
                    SeqListPush_front(&my_list,item);
                }
                break;
            case Pop_back:
                SeqListPop_back(&my_list);
                break;
            case Pop_front:
                SeqListPop_front(&my_list);
                break;
            case Show_List:
                SeqListShow_List(&my_list);
                break;
            case List_length:
                SeqList_length(&my_list);
                break;
            case List_capacity:
                SeqList_capacity(&my_list);
                break;
            case Insert_pos:
                SeqListInsert_pos(&my_list,pos,key);
                break;
            case Delete_pos:
                SeqListDelect_pos(&my_list,pos);
                break;
            case Find:
                SeqListFind(&my_list,pos);
                break;
            case Sort:
                SeqListSort(&my_list);
                break;
            case Reverse:
                SeqListReverse(&my_list);
                break;
            case Remove_All:
                SeqListRemove_All(&my_list,key);
                break;
            case Clear:
                SeqListClear(&my_list);
                break;
            case Destory_List:
                break;
            case Find_binary:
                break;
            case Exit:
                select = 0;
                printf("Exit successful!\n");
                break;
            default:
                printf("Select error,please try again!\n");
                break;
        }
    }
    return 0;
}