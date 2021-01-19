//
// Created by 胡杨 on 2021/1/18.
//

#ifndef SINGLE_LIST_SINGLE_LIST_H
#define SINGLE_LIST_SINGLE_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string.h>

//定义元素类型
#define ElemType int

//定义单链表结点
typedef struct ListNode
{
    ElemType data;
    struct ListNode *next;
}SlistNode;

//定义单链表
typedef struct Slist
{
    struct ListNode *head;
}Slist;


//函数声明
extern void Init_List(Slist *plist);
extern void SlistPushBack(Slist *plist,ElemType x);
extern void SlistPopBack(Slist *plist);
extern void SlistPushFront(Slist *plist,ElemType x);
extern void SlistPopFront(Slist *plist);
extern int  SlistLength(Slist *plist);
extern void SlistSort(Slist *plist);
extern void SlistInsert_val(Slist *plist,ElemType x);
extern void SlistDelect_val(Slist *plist,ElemType key);
extern SlistNode* SlistFind(Slist *plist,ElemType key);
extern void SlistReverse(Slist *plist);
extern void SlistShow(Slist *plist);
extern void SlistClear(Slist *plist);
extern void SlistDestory(Slist *plist);










#endif //SINGLE_LIST_SINGLE_LIST_H
