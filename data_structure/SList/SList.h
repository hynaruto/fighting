//
// Created by 胡杨 on 2021/1/24.
//

#ifndef SLIST_SLIST_H
#define SLIST_SLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int SLTDateType;

//定义链表结点
typedef  struct  SListNode
{
    SLTDateType data;
    struct SListNode* next;
}SListNode;

//声明
extern void InitSList(SListNode **pList);
extern void SListPush_Back(SListNode **plist,SLTDateType x);
extern void SListShow_List(SListNode *plist);
extern void SListPop_back(SListNode **plist);
extern void SListPush_Front(SListNode **plist,SLTDateType x);
extern void SListPop_Front(SListNode **plist);
extern SListNode* SListFind(SListNode *plist,SLTDateType key);
extern void  SlistInsertAfter(SListNode **plist,SLTDateType x,SLTDateType key);
extern void SListEraseAfter(SListNode **plist,SLTDateType key);
extern void SListDestory(SListNode **plist);


#endif //SLIST_SLIST_H
