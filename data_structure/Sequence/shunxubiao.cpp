#include <cstring>
#include <stdio.h>

using namespace std;

#define Maxsize 100
#define ElemType int
#define Status int
typedef struct
{
    ElemType data [Maxsize];
    int length;
}SqList;
//初始化顺序表
Status InitList(SqList &L)
{
    //初始化长度为0；
    L.length = 0;
    //初始化数据为0；
    memset(L.data,0, sizeof(L));
    return 0;
}
//创建顺序表，初始化前N个数据；
bool CreateList(SqList &L,int n)
{
    if (n < 0 || n > Maxsize)
    {
        return false;
    }
    int i = 0;
    for (i = 0;i < n;i++)
    {
        scanf("%d",&L.data[i]);
        L.length++;
    }
    return true;
}
//在位置I出插入数据
bool InsertList(SqList &L,int i ,ElemType e)
{
    //判断位置是否有效
    if (i < 1 || i > L.length)
    {
        printf("插入的位置无效！");
        return false;
    }
    //判断顺序表是否已满
    if (L.length > Maxsize)
    {
        printf("当前空间已满！");
        return false;
    }
    int j ;
    for (j = L.length;j >= i;j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}
//删除顺序表中i处的元素
bool ListDelete(SqList &L,int i)
{
    if  (i < 1 || i > L.length)
    {
        printf("顺序表已满,位置已满！");
        return false;
    }
    for (int j = L.length;j <= L.length - 1;j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
//查找顺序表里的一个元素e，并返回位置
int LocateElem(SqList L,ElemType e)
{
    for (int i = 0;i < L.length;i++)
    {
        if (L.data[i] == e)
        {
            return i+1;
        }
    }
    return 0;
}
//将顺序表倒置
void Reverse(SqList &L)
{
    if (L.length)
    {
        for (int i = 0;i < L.length - 1 - i;i++)
        {
            int j = L.data[i];
            L.data[i] = L.data[L.length - 1 - i];
            L.data[L.length - 1 -i] = j;
        }
    }
}
//清空顺序表
void ClearList(SqList &L)
{
    L.length = 0;
}
//功能函数
void PrintList(SqList &L)
{
    printf("当前顺序表所有元素：");
    for (int i = 0;i < L.length;i++)
    {
        printf("%d",L.data[i]);
    }
    printf("\n");
}
//创建顺序表函数
void Create(SqList &L)
{
    int n;
    bool flag;
    L.length = 0;
    printf("输入创建顺序表的长度.");
    scanf("%d",&n);
    printf("输入%d个数(空格隔开):",n);
    flag = CreateList(L,n);
    if (flag)
    {
        printf("创建成功！\n");
        PrintList(L);
    } else{
        printf("输入长度非法！");
    }

}
void Insert(SqList &L)
{
    int place;ElemType e;bool flag;
    printf("请输入要插入的位置(从1开始)及元素：\n");
    scanf("%d%d",&place,&e);
    if (flag)
    {
        printf("插入成功！");
        PrintList(L);
    }
}
void Delete(SqList &L)
{
    int place;bool flag;
    printf("请输入要删除元素的位置(从1开始)：");
    scanf("%d",&place);
    if (flag)
    {
        printf("删除元素成功！");
        PrintList(L);
    }
}
void Search(SqList L)
{
    ElemType e;
    int flag;
    printf("请输入要查找的元素：\n");
    scanf("%d",&e);
    flag = LocateElem(L,e);
    if (flag)
    {
        printf("该元素的位置为：%d\n",flag);
    } else
    {
        printf("找不到该元素!");
    }
}
void menu()
{
    printf("******1.创建                       2.插入******");
    printf("******3.删除                       4.查找******");
    printf("******5.倒置                       6.输出******");
    printf("******7.清空                       8.退出******");
}
int mian()
{
    SqList L;
    int choice;
    while (1)
    {
        menu();
        printf("请输入菜单序号:\n");
        scanf("%d",&choice);
        if (9 == choice)
        {
            break;
        }
        switch (choice)
        {
            case 1:Create(L);
                break;
            case 2:Insert(L);
                break;
            case 3:Delete(L);
                break;
            case 4:Search(L);
                break;
            case 5:Reverse(L);
                break;
            case 7:PrintList(L);
                break;
            case 8:ClearList(L);
                break;
            default:printf("输入错误！！！\n");
        }
    }
    return 0;
}