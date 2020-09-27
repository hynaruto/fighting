#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define SElemType int
#define Status    int
#define MaxSize   100

//定义顺序栈的两个指针和元素类型;
typedef struct Stack
{
    SElemType *base; //栈底
    SElemType *top;  //栈顶
    int stacksize;
}SqStack;

//初始化函数
Status InitStack(SqStack &s)
{
    s.base = new SElemType[MaxSize];
    if (!s.base)
    {
        printf("顺序栈初始化失败");
        return 0;
    }
    s.top = s.base;
    s.stacksize = MaxSize;
    return 1;
}

//元素入栈
Status Push(SqStack &s,SElemType e)
{
    if (s.top - s.base == s.stacksize) //判断栈满
    {
        return 0;
    }
    *(s.top++) = e;
    return 1;
}

//元素出栈
Status Pop(SqStack &s,SElemType &e)
{
    if (s.top == s.base) //判断栈空
    {
        return 0;
    }
    *--s.top = e;
    return 1;
}

//不通过修改指针,获得栈顶元素
bool GetTop(SqStack s,SElemType &e)
{
    if (s.top == s.base)
    {
        return false;
    } else{
        *--s.top = e;
    }
    return true;
}

//菜单
void menu()
{
    printf("****    1.入栈    ****");
    printf("****    2.出栈    ****");
    printf("****    3.取栈顶元素    ****");
    printf("****    4.退出    ****");
}

//入栈功能函数
void PushStack(SqStack &s)
{
    int tmp;
    SElemType e;
    printf("输入元素入栈个数:\n");
    scanf("%d",&e);
    for (int i = 0;i < tmp;i++)
    {
        printf("输入第%d个元素的值：\n");
        scanf("%d",&e);
        int flag;
        flag = Pop(s,e);
        if (flag)
        {
            printf("%d已经入栈\n",e);
        }
        else{
            printf("栈空！\n");
        }
    }
}

//取栈顶功能函数
void  GetTopStack(SqStack &s)
{
    SElemType e;
    bool flag;
    flag = GetTop(s,e);
    if (flag)
    {
        printf("栈顶元素为%d\n",e);
    }else{
        printf("栈空！");
    }
}

//出栈功能函数
void PopStack(SqStack &s)
{
    int n;
    SElemType e;
    int flag;
    printf("输入出栈元素个数:\n");
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
    {
        flag = Pop(s,e);
        if (flag)
        {
            printf("%d已出栈\n",e);
        } else{
            printf("栈已空！");
            break;
        }
    }
}


int main()
{
    SqStack s;
    int choice;
    InitStack(s);

    while (1)
    {
        menu();
        printf("请输入菜单序号：\n");
        scanf("%d",&choice);
        if (choice == 4)
        {
            break;
        }
        switch (choice)
        {
            case 1:PushStack(s);
                break;

            case 2:PopStack(s);
                break;

            case 3:GetTopStack(s);
                break;

            default:
                printf("输入错误！！！\n");
        }

    }
    return 0;

}