//
// Created by 胡杨 on 2021/1/17.
//

#ifndef SEQLIST_SEQLIST_H
#define SEQLIST_SEQLIST_H

#endif //SEQLIST_SEQLIST_H
//头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//定义数据类型
#define ELEMTYPE int
//定义顺序表初始大小
#define List_Size 4
//定义每次扩容的单位大小
#define INC 8
//顺序表结构体声明
typedef struct SeqList
{
    ELEMTYPE *base;
    //顺序表当前大小
    size_t size;
    //顺序表的容量
    size_t capacity;
}SeqList;


//函数声明
extern void InitSeqList(SeqList *p);
extern void SeqListPush_back(SeqList *p,ELEMTYPE x);
extern void SeqListShow_List(SeqList *p);
extern void SeqListPush_front(SeqList *p,ELEMTYPE x);
extern void SeqListPop_back(SeqList *p);
extern void SeqListPop_front(SeqList *p);
extern int SeqList_length(SeqList *p);
extern int SeqList_capacity(SeqList *p);
extern size_t SeqListInsert_pos(SeqList *p,ELEMTYPE pos,ELEMTYPE key);
extern int  SeqListFind(SeqList *p,ELEMTYPE key);
extern void SeqListSort(SeqList *p);
extern void SeqListClear(SeqList *p);
extern void SeqListDelect_pos(SeqList *p ,ELEMTYPE pos);
extern void SeqListReverse(SeqList *p);
extern void SeqListRemove_All(SeqList *p,ELEMTYPE key);