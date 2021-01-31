//
// Created by 胡杨 on 2021/1/31.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define Elemtype int

//定义堆空间
typedef struct Heap
{
    Elemtype *heap;
    size_t capacity;
    size_t size;
}Heap;

//声明
extern void HeapInit(Heap *php,int size);
extern void HeapInsert(Heap *php,Elemtype x);
extern void HeapShow(Heap *php);
extern Elemtype HeapTop(Heap *php);
extern void HeapRemove(Heap *php);
extern bool HeapIsFull(Heap *php);
extern bool HeapIsEmpty(Heap *php);
extern void HeapInitByArr(Heap *php,Elemtype arr[],Elemtype n);
extern void AdjustDown(Heap *php,int start);
extern void AdjustUp(Heap *php,int start);
extern void HeapClear(Heap *php);
extern void HeapDestory(Heap *php);
















#endif //HEAP_HEAP_H
