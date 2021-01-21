//
// Created by 胡杨 on 2021/1/21.
//

#ifndef DCLIST_DCLIST_H
#define DCLIST_DCLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define Elempty int

//定义带头双循环链表的结点
typedef struct DCListNode
{
    Elempty data;
    struct DCListNode *next;
    struct DCListNode *pre;
}DCListNode;

typedef struct DCList
{
    DCListNode *first;
    DCListNode *last;
    Elempty size;
}DCList;

//声明
extern void DCListInit(DCList * plist);
extern void DCListPushBack(DCList *plist,Elempty x);
extern void DCListShow(DCList *plist);
extern void DCListPopBack(DCList *plist);
extern void DCListPushFront(DCList *plist,Elempty x);
extern void DCListPopFront(DCList *plist);
extern size_t DCListlength(DCList *plist);
extern void DCListSort(DCList *plist);
extern void DCListInsert_val(DCList *plist,Elempty x);
extern void DCListDelect_val(DCList *plist,Elempty key);
extern DCListNode* DCListFind(DCList *plist,Elempty key);
extern void DCLIstInsert_pos(DCList *plist,Elempty x,Elempty pos);
extern void DCListDelect_pos(DCList *plist,Elempty pos);
extern void DCListReverse(DCList *plist);
extern void DCListClear(DCList *plist);
extern void DCListDestory(DCList *plist);
extern void DCLIstRemoveAll(DCList *plist,Elempty x);










#endif //DCLIST_DCLIST_H
