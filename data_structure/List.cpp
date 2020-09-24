#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//创建节点（结构体）
struct Node
{
    int a;
    struct Node* next;
};
//定义链表的头尾指针
struct Node* head = NULL;
struct Node* end  = NULL;
//创建链表，在链表中增加一个数据
void AddListFull(int a )
{
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp ->a = a;
    tmp ->next = NULL;
    if (NULL == head)
    {
        head = tmp;
    } else{
        end ->next = tmp;
    }
    end = tmp;
}

//遍历链表
void ScanList()
{
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d\n",tmp -> a);
        tmp = tmp ->next;
    }
}

//查询指定节点
struct Node* FindNode(int a)
{
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        if(a == tmp ->a)
        {
            return tmp;
        }
        tmp = tmp ->next;
    }
    return NULL;
}

//在指定位置插入节点
void AddList(int index,int a)
{
    if (head == NULL)
    {
        printf("链表为空!");
        return;
    }
    struct Node *pf = FindNode(index);
    if (pf == NULL)
    {
        printf("没有此节点");
        return;
    }
    struct Node* tmp  = (struct Node *)malloc(sizeof(struct Node));
    tmp ->a = a;
    tmp ->next = NULL;
    if (pf == end)
    {
        end ->next = tmp;
        end = tmp;
    } else{
        tmp -> next = pf ->next;
        pf -> next = tmp;
    }
}

//删除链表尾部元素
void  DeleteListTail()
{
    if (head == NULL)
    {
        printf("链表为空!");
        return;
    }
    if(head == end)
    {
        free(head);
        head = NULL;
        end = NULL;
    } else{
        struct Node* tmp = head;
        while (tmp ->next != end)
        {
            tmp = tmp -> next;
        }
        free(end);
        end = tmp;
        end ->next = NULL;
    }
}

//删除链表头节点
void DeleteListHead()
{
    struct Node* tmp = head;
    if (head == NULL)
    {
        printf("链表为空！");
        return;
    }
    head = tmp -> next;
    free(tmp);
}

//删除指定节点
void DeleteListRand(int a)
{
    if (head == NULL)
    {
        printf("链表为空！");
        return;
    }
    struct Node* tmp = FindNode(a);
    if (tmp == NULL)
    {
        printf("没有此点!");
        return;
    }
    if (head == end)
    {
        free(head);
        head = NULL;
        end = NULL;
    }
    else if (head ->next == end)
    {
        if (end == tmp)
        {
            DeleteListTail();
        }
        else if (head == tmp)
        {
            DeleteListHead();
        } else{
            struct Node *pf = head;
            while (pf ->next != tmp)
            {
                pf = pf ->next;
            }
            pf ->next = tmp ->next;
            free(tmp);
        }
    }
}

int  main()
{
    int i;
    struct Node *pFind;
    for (i = 0;i < 6;i++)
    {
        AddListFull(i);
    }
    AddList(4,14);
    DeleteListTail();
    DeleteListRand(4);
    ScanList();
    pFind = FindNode(5);
    if (pFind != NULL)
    {
        printf("找到%d\n",pFind ->a);
    } else{
        printf("没有找到元素！");
    }



    return 0;
}
