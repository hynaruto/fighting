//
// Created by 胡杨 on 2021/1/24.
//

#ifndef STACK_SQ_STACK_SQ_H
#define STACK_SQ_STACK_SQ_H


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define StackElemType int

#define SEQSTACK_DEFAULT_SIZE 8

typedef struct SeqStack
{
    StackElemType *base; //
    size_t         capacity;
    int            top;
}SeqStack;


void SeqStackInit(SeqStack *pst, int sz);
void SeqStackDestroy(SeqStack *pst);
void SeqStackPush(SeqStack *pst, StackElemType x);
void SeqStackPop(SeqStack *pst);
StackElemType SeqStackTop(SeqStack *pst);
void SeqStackShow(SeqStack *pst);

bool IsFull(SeqStack *pst)
{return pst->top >= pst->capacity;}
bool IsEmpty(SeqStack *pst)
{return pst->top == 0;}

void SeqStackInit(SeqStack *pst, int sz)
{
    assert(pst);
    pst->capacity = sz > SEQSTACK_DEFAULT_SIZE ? sz : SEQSTACK_DEFAULT_SIZE;
    pst->base = (StackElemType*)malloc(sizeof(StackElemType) * pst->capacity);
    assert(pst->base != NULL);
    pst->top = 0;
}

void SeqStackPush(SeqStack *pst, StackElemType x)
{
    assert(pst);
    if(IsFull(pst))
    {
        printf("栈空间已满，%d不能入栈\n", x);
        return;
    }
    pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack *pst)
{
    assert(pst);
    if(IsEmpty(pst))
    {
        printf("栈已空，不能出栈.\n");
        return;
    }
    pst->top--;
}

StackElemType SeqStackTop(SeqStack *pst)
{
    assert(pst && !IsEmpty(pst));
    return pst->base[pst->top-1];
}

void SeqStackShow(SeqStack *pst)
{
    assert(pst);
    for(int i=pst->top-1; i>=0; --i)
        printf("%d\n", pst->base[i]);
}

void SeqStackDestroy(SeqStack *pst)
{
    assert(pst);
    free(pst->base);
    pst->base = NULL;
    pst->capacity = pst->top = 0;
}

#endif //STACK_SQ_STACK_SQ_H
