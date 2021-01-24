//
// Created by 胡杨 on 2021/1/24.
//
#include "SList.h"

//初始化链表
void InitSList(SListNode **pList)
{
    //assert(pList);
    *pList = NULL;
}

//购买结点
static SListNode* BuySListNode(SLTDateType x)
{
    SListNode *s = NULL;
    s = (SListNode*)malloc(sizeof(SListNode));
    assert(s);
    s ->data = x;
    s ->next = NULL;
    return  s;
}

//尾部插入
void SListPush_Back(SListNode **plist,SLTDateType x)
{
    //assert(plist);
    SListNode *s = BuySListNode(x);
    SListNode *p = *plist;
    assert(s != NULL);
    //如果链表为空
    if (*plist == NULL)
    {
        *plist = s;
    } else{
        //链表不为空
        while (p ->next != NULL)
        {
            p = p ->next;
        }
        p ->next = s;
    }
}

//尾部删除
void SListPop_back(SListNode **plist)
{
    SListNode *p = *plist;
    //如果链表为空
   if (p == NULL || p ->next ==NULL)
   {
       free(p);
       *plist = NULL;
   }else{
        SListNode *pre = NULL;
        while (p ->next)
        {
            pre = p;
            p = p ->next;
        }
        pre ->next = NULL;
    }
    free(p);
}

//头部插入
void SListPush_Front(SListNode **plist,SLTDateType x)
{
    //assert(plist);
    SListNode *s = BuySListNode(x);
    SListNode *p = *plist;
    //如果链表为空
    if (*plist == NULL)
    {
        *plist = s;
    } else{
        s ->next = p;
        *plist = s;
    }

}

//头部删除
void SListPop_Front(SListNode **plist)
{
    //assert(plist);
    //如果链表为空
    if (*plist == NULL)
    {
        return;
    }
    //如果链表只有一个结点
    SListNode *cur = *plist;
    if (cur ->next == NULL)
    {
        free(cur);
        *plist = NULL;
    } else{
        SListNode *p = *plist;
        *plist = (*plist) ->next;
        free(p);
    }
}

//查找函数
SListNode* SListFind(SListNode *plist,SLTDateType key)
{
    assert(plist);
    SListNode *p = plist;
    while (p != NULL)
    {
        if (p ->data == key)
        {
            printf("the %d is find\n",p ->data);
            return p;
        }
        p = p ->next;
    }
    return NULL;
}

//在pos之后插入x
void  SlistInsertAfter(SListNode**plist,SLTDateType x,SLTDateType key)
{
    assert(plist);
    SListNode *s = BuySListNode(x);
    if ((*plist) != NULL)
    {
        //找到往哪插的pos
        SListNode *pos = SListFind(*plist,key);
        if (pos == NULL)
        {
            return;
        } else{
            //pos存在
            s ->next = pos ->next;
            pos ->next = s;
        }
    } else{
        //链表为空
        SListPush_Back(plist,x);
    }
}

//删除pos位置之后的值(删除一个)
void SListEraseAfter(SListNode **plist,SLTDateType key)
{
    assert(plist);
    //如果链表为空或者如果链表中只有一个结点，且是要删除的位置
    if ((*plist) == NULL || (*plist) ->next == NULL)
    {
        return;
    }
    SListNode *pos = SListFind(*plist,key);
    if (pos != NULL)
    {
        if (pos ->next == NULL)
        {
            return;
        } else{
            pos ->next = pos ->next ->next;
        }
    } else{
        return;
    }
}

//摧毁链表
void SListDestory(SListNode **plist)
{
    assert(plist);
    SListNode *p = *plist;
    SListNode *q = *plist;
    if (p == NULL)
    {
        return;
    } else{
        while (q)
        {
            q = p ->next;
            free(p);
            p = q;
        }
    }
    *plist = NULL;
}

//显示函数
void SListShow_List(SListNode *plist)
{
    //assert(plist);
    SListNode *p = plist;
    while (p)
    {
        printf("%d-->",p ->data);
        p = p ->next;
    }
    printf("Over\n");
}
