#include "SList.h"

void Menu()
{
    printf("****************************************************\n");
    printf("***1.Push_Back****************2.Pop_back************\n");
    printf("***3.Push_Front***************4.Pop_front***********\n");
    printf("***5.Show_List****************6.Find****************\n");
    printf("***7.InsertAfter**************8.EraseAfter**********\n");
    printf("***9.Destory******************0.Exit****************\n");
    printf("****************************************************\n");
    printf("Please select:\n");
}
enum {
    Exit,Push_Back,Pop_Back,Push_Front,Pop_Front,Show_List,Find,InsterAfter,EraseAfter,Destory
};

int main()
{
    SListNode * list;
    SLTDateType item,key,pos;
    InitSList(&list);
    int select = 1;
    while (select)
    {
        Menu();
        scanf("%d",&select);
        switch (select)
        {
            case Push_Back:
                printf("please enter the item(end by -1):\n");
                while ((scanf("%d",&item)) && item != -1)
                {
                    SListPush_Back(&list,item);
                }
                break;
            case Pop_Back:
                SListPop_back(&list);
                break;
            case Push_Front:
                printf("please enter the item(end by -1):\n");
                while ((scanf("%d",&item)) && item != -1)
                {
                    SListPush_Front(&list,item);
                }
                break;
            case Pop_Front:
                SListPop_Front(&list);
                break;
            case Show_List:
                SListShow_List(list);
                break;
            case Find:
                printf("please enter the key:\n");
                scanf("%d",&key);
                SListFind(list,key);
                break;
            case InsterAfter:
                printf("please enter the key:\n");//你要往哪插
                scanf("%d",&key);
                printf("please enter the item：\n");//插什么data
                scanf("%d",&item);
                SlistInsertAfter(&list,item,key);
                break;
            case EraseAfter:
                printf("please choose the key:\n");
                scanf("%d",&key);
                SListEraseAfter(&list,key);
                break;
            case Destory:
                SListDestory(&list);
                break;
            case Exit:
                printf("Exit successful!\n");
                select = 0;
                break;
            default:
                printf("select error,please select again!\n");
                break;
        }
    }
    return 0;
}