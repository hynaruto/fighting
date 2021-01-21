//
// Created by 胡杨 on 2021/1/21.
//

#include "DCList.h"

//为结点申请空间
static DCListNode* DCListBuyNode(Elempty x)
{
    DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
    assert(s != NULL);
    s ->next = s ->pre = NULL;
    s ->data = x;
    return s;
}
//双向循环链表的初始化
void DCListInit(DCList * plist)
{
    assert(plist);
    DCListNode *s = DCListBuyNode(0);
    plist ->first = plist ->last = s;
    plist ->last ->next = plist ->first;
    plist ->first ->pre = plist ->last;
    plist ->size = 0;
}
//尾部插入
void DCListPushBack(DCList *plist,Elempty x)
{
    assert(plist);
    DCListNode *s = DCListBuyNode(x);
    s ->pre = plist ->last;
    plist ->last ->next = s;
    plist ->last = s;
    plist ->last ->next = plist ->first;
    plist ->first ->pre = plist ->last;
    plist ->size++;
}

//尾部删除
void  DCListPopBack(DCList *plist)
{
    assert(plist);
    DCListNode *p = plist ->last;
    //如果链表不为空
    if (p != plist ->first)
    {
        plist ->last = p ->pre;
        plist ->last ->next = plist ->first;
        plist ->first ->pre = plist ->last;
        free(p);
        plist ->size--;
    }
}

//头部插入
void DCListPushFront(DCList *plist,Elempty x)
{
    assert(plist);
    DCListNode *s = DCListBuyNode(x);
    //如果链表为空,last指针需要移动
    if (plist ->last == plist ->first)
    {
        plist ->last = s;
    }
    s ->next = plist ->first ->next;
    plist ->first ->next ->pre = s;
    plist ->first ->next = s;
    s ->pre = plist ->first;
    plist ->size++;
}

//头部删除
void DCListPopFront(DCList *plist)
{
    assert(plist);
    //如果链表为空
    if (plist ->size == 0)
    {
        return;
    }
    DCListNode *p = plist ->first ->next;
    p ->pre ->next = p ->next;
    p ->next ->pre = p ->pre;
    free(p);
    plist ->size--;
    //如果删除到链表为空，那么需要动last
    if (plist ->size == 0)
    {
        plist ->last = plist ->first;
    }
    plist ->size--;
}

//显示函数
void DCListShow(DCList *plist)
{
    assert(plist);
    DCListNode *p = plist ->first ->next;
    while (p != plist ->first)
    {
        printf("%d-->",p ->data);
        p = p ->next;
    }
    printf("Over!\n");
}

//求链表长度
size_t DCListlength(DCList *plist)
{
    return plist ->size;
}

//按值插入
void DCListInsert_val(DCList *plist,Elempty x)
{
    assert(plist);
    DCListNode *s = DCListBuyNode(x);
    DCListNode *p = plist ->first ->next;
    while (p != plist ->first && x > p ->data)
    {
        p = p ->next;
    }
    //目标值在最后一位
    if (p == plist ->first)
    {
        plist ->last = s;
    }
    //目标值不在最后一位,开始插入
    s ->next = p;
    s ->pre = p ->pre;
    s ->pre ->next = s;
    s ->next ->pre = s;
    plist ->size++;
}

//查找
DCListNode* DCListFind(DCList *plist,Elempty key)
{
    assert(plist);
    DCListNode *p = plist ->first ->next;
    while (p != plist ->first && key != p ->data)
    {
        p = p ->next;
    }
    if (p == plist ->first)
    {
        return NULL;
    }
    return p;
}

//按值删除
void DCListDelect_val(DCList *plist,Elempty key)
{
    assert(plist);
    DCListNode *p = DCListFind(plist,key);
    if (p != NULL)
    {
        //判断删除的是不是最后一个结点
        if (p == plist ->last)
        {
            plist ->last = p ->pre;
        }
        p ->pre ->next = p ->next;
        p ->next ->pre = p ->pre;
        free(p);
        plist ->size--;
    }
}

//按照指定位置插入（在pos的前面插入）
void DCLIstInsert_pos(DCList *plist,Elempty x,Elempty y)
{
    assert(plist);
    DCListNode *s = DCListBuyNode(x);
    DCListNode *pos = DCListFind(plist,y);
    assert(pos != NULL);
    //当链表不为空时
    if (plist ->first != plist ->last)
    {
        s ->next = pos;
        s ->pre = pos ->pre;
        s ->pre ->next = s;
        pos ->pre = s;
    }
    plist ->size++;
}

//按照指定位置删除
void DCListDelect_pos(DCList *plist,Elempty pos)
{
    assert(plist);
    DCListNode *p = plist ->first ->next;
    int count = 1;
    while (count < pos)
    {
        p = p ->next;
        count = count + 1;
    }
    //找到了pos位置的元素
    DCListNode *cur = DCListFind(plist,p ->data);
    //开始删除
    if (plist ->first != plist ->last)
    {
        //如果此结点是最后一个结点
        if (plist ->last == cur)
        {
            plist ->last = cur ->pre;
            plist ->last ->next = plist ->first;
            plist ->first ->pre = plist ->last;
        } else{
            cur ->pre ->next = cur ->next;
            cur ->next ->pre = cur ->pre;
        }
        plist ->size--;
        free(cur);
    }
}

//翻转链表
void DCListReverse(DCList *plist)
{
    assert(plist);
    DCListNode *p = plist ->first ->next;
    DCListNode *q;
    //如果链表为空或者链表只有一个结点，不需要翻转
    if (plist ->size < 1)
    {
        return;
    }
    //切割
    q = p ->next;
    plist ->last = p;
    plist ->last ->next = plist ->first;
    plist ->first ->pre = plist ->last;
    //开始一一头插
    while (q != plist ->first)
    {
        p = q;
        q = q ->next;
        p ->next = plist ->first ->next;
        p ->next ->pre = p;
        p ->pre = plist ->first;
        p ->pre ->next = p;
    }
}

//清空链表
void DCListClear(DCList *plist)
{
    assert(plist);
    DCListNode *p = plist ->first ->next;
    if (plist ->size == 0)
    {
        return;
    }
    while (p != plist ->first)
    {
        p ->pre ->next = p ->next;
        p ->next ->pre = p ->pre;
        free(p);
        p = plist ->first ->next;
    }
    plist ->size = 0;
    plist ->last = plist ->first;
}

//摧毁链表
void DCListDestory(DCList *plist)
{
    assert(plist);
    DCListClear(plist);
    free(plist ->first);
    plist ->first = plist ->last = NULL;
    plist ->size = 0;
}

//删除链表中所有相同的元素
void DCLIstRemoveAll(DCList *plist,Elempty x)
{
    assert(plist);
    DCListNode *p = plist ->first ->next;
    while (p != plist ->first)
    {
        if (p ->data == x)
        {
            p ->pre ->next = p ->next;
            p ->next ->pre = p ->pre;
            p = p ->next;
            free(p);
            continue;
        }
        p = p ->next;
    }
}

//链表排序
void DCListSort(DCList *plist)
{
    assert(plist);
    DCListNode *p = plist ->first ->next;
    DCListNode *tmp = plist ->first ->next;
    if (plist ->size <= 1)
    {
        return;
    }
    DCListNode *q = p ->next;
    p ->next = plist ->last ->next;
    plist ->last = q ->pre;
    while (q != plist ->first)
    {
        p = q;
        q = q ->next;
        while (tmp ->data < p ->data && tmp ->next != plist ->first)
        {
            tmp = tmp ->next;
        }
        if (tmp ->data < p ->data)
        {
            p ->next = tmp ->next;
            p ->pre = tmp ->next ->pre;
            p ->next ->pre = p;
            p ->pre ->next = p;
        } else{
            p ->next = tmp ->pre ->next;
            p ->pre = tmp ->pre;
            p ->next ->pre = p;
            p ->pre ->next = p;
        }
        tmp = plist ->first ->next;
    }
}