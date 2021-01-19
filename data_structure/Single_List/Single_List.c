//
// Created by 胡杨 on 2021/1/18.
//
#include "Single_List.h"

//此函数用来申请结点
static SlistNode* BuyNode()
{
    SlistNode *s = (SlistNode*)malloc(sizeof(SlistNode));
    assert(s != NULL);
    s ->data = 0;
    s ->next = NULL;
    return s;
}

//初始化单链表
void Init_List(Slist *plist)
{
    plist ->head = NULL;
}

//尾插
void  SlistPushBack(Slist *plist,ElemType x)
{
    assert(plist);
    SlistNode *s = BuyNode();
    s ->data = x;
    //查找链表的尾部
    SlistNode *p = plist ->head;
    //若当前链表为空
    if (p == NULL)
    {
        //直接插入结点
        plist ->head = s;
    } else{
        //当前链表不为空
        while (p ->next != NULL)
        {
            p = p ->next;
        }
        p ->next = s;
    }
}

//从尾部删除
void SlistPopBack(Slist *plist)
{
    assert(plist);
    SlistNode *p = plist ->head;
    //如果链表为空
    if (p != NULL)
    {
        //如果只有一个结点
        if (p ->next == NULL)
        {
            plist ->head = NULL;
        } else{
            //有多个结点存在
            SlistNode *pre = NULL;
            while (p ->next != NULL)
            {
                pre = p;
                p = p ->next;
            }
            //删除结点
            pre ->next = NULL;
        }
    } else{
        printf("the list is empty\n");
    }
    free(p);
}

//头部插入
void SlistPushFront(Slist *plist,ElemType x)
{
    assert(plist);
    //申请结点空间
    SlistNode *s = BuyNode();
    s ->data = x;
    s ->next =NULL;
    //头插
    s ->next = plist ->head;
    plist ->head = s;
}

//头部删除
void SlistPopFront(Slist *plist)
{
    assert(plist);
    SlistNode *p = plist ->head;
    //保证链表不为空的前提下
    if (p != NULL)
    {
        //如果链表只有一个结点
        if (p ->next == NULL)
        {
            plist ->head = NULL;
        } else{
            //链表有多个结点
            plist ->head = p ->next;
            free(p);
        }
    }
}

//显示链表长度
int SlistLength(Slist *plist)
{
    assert(plist);
    int count = 0;
    SlistNode *p = plist ->head;
    if (p != NULL)
    {
        while (p != NULL)
        {
            count++;
            p = p ->next;
        }
        printf("the list length is: %d\n",count);
        return 0;
    } else{
        printf("the list is empty!\n");
        return -1;
    }
}
//显示链表
void SlistShow(Slist *plist)
{
    assert(plist);
    SlistNode *p = plist ->head;
    if (p == NULL)
    {
        printf("Empty!\n");
    } else{
        while (p != NULL)
        {
            printf("%d-->",p ->data);
            p = p ->next;
        }
        printf("Over!\n");
    }
}

//对链表进行排序
void SlistSort(Slist *plist)
{
    assert(plist);
    SlistNode *p = plist ->head;
    SlistNode *q;
    //1.链表为空
    if (p == NULL)
    {
        printf("the list is empty!\n");
    }
    //2.链表只有一个元素
    if (p ->next == NULL)
    {
        SlistShow(plist);
    }
    //3.链表有多个元素->排序
    int len = SlistLength(plist);
    int i,j,tmp;
    for (i = 0;i < len - 1;++i)
    {
        p = p ->next;
        for (j = i + 1;j < len;++j)
        {
            q = p ->next;
            if (p ->data > q ->data)
            {
                tmp = p ->data;
                p ->data = q ->data;
                q ->data = tmp;
            }
            q = q ->next;
        }
    }
    SlistShow(plist);
}

//按值插入
void SlistInsert_val(Slist *plist,ElemType x)
{
    assert(plist);
    //给x申请空间
    SlistNode *s = BuyNode();
    s ->data = x;
    //如果链表为空
    if (plist ->head == NULL)
    {
        plist ->head = s;
    } else{
        //链表不为空
        SlistNode *p = plist ->head;
        SlistNode* pre = NULL;
        while (p != NULL && x > p ->data)
        {
            pre = p;
            p = p ->next;
        }
        //1.插入结点在头部
        if (pre == NULL)
        {
            //在链表的头部插入
            s ->next = p;
            plist ->head = s;
        } else{
            s ->next = pre->next;
            pre ->next = s;
        }
    }
}

//按值删除
void SlistDelect_val(Slist *plist,ElemType key)
{
    assert(plist);
    SlistNode *p = plist ->head;
    SlistNode *pre = NULL;
    //找到key
    while (p != NULL && p ->data != key)
    {
        pre = p;
        p = p ->next;
    }
    //找到了
    if (p != NULL)
    {
        //找到了,开始删除
        //1.要删除的值在头部
        if (pre == NULL)
        {
            plist ->head = p ->next;
        }else{
            pre ->next = p ->next;
        }
        free(p);
    }
}

//链表的查找
SlistNode* SlistFind(Slist *plist,ElemType key)
{
    assert(plist);
    SlistNode *p = plist ->head;
    while (p != NULL && p ->data != key)
    {
        p = p ->next;
    }
    return p;
}

//链表的翻转
void SlistReverse(Slist *plist)
{
    //思想：1.切割 2. 头插
    assert(plist);
    SlistNode *p;
    SlistNode *q;
    //如果链表为空
    if (plist ->head == NULL)
    {
        return;
    }
    //如果链表只有一个结点，那么不用翻转
    if (plist ->head ->next == NULL)
    {
        return;
    }
    //切割链表
    p = plist ->head ->next;
    plist ->head ->next = NULL;
    //将剩余的部分头插
    q = p;
    while (q != NULL)
    {
        q = q ->next;
        p ->next = plist ->head;
        plist ->head = p;
        p = q;
    }
}

//清空链表
void SlistClear(Slist *plist)
{
    assert(plist);
    SlistNode *p = plist ->head;
    while (p != NULL)
    {
        plist ->head = p ->next;
        free(p);
        p = plist ->head;
    }
}

//摧毁链表
void SlistDestory(Slist *plist)
{
    assert(plist);
    SlistClear(plist);
}