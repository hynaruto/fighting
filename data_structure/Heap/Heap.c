//
// Created by 胡杨 on 2021/1/31.
//

#include "Heap.h"

//按值初始化
void HeapInit(Heap *php,int size)
{
    assert(php);
    php ->heap = (Elemtype*)malloc(sizeof(Elemtype) * size);
    assert(php ->heap);
    memset(php ->heap,0, sizeof(Elemtype) * size);
    php ->capacity = size;
    php ->size = 0;
}
//循环初始化
void HeapInitByArr(Heap *php,Elemtype arr[],Elemtype n)
{
    assert(php);
    php ->heap = (Elemtype*)malloc(sizeof(Elemtype) * n);
    assert(php ->heap);
    php ->capacity = n;
    php ->size = 0;
    for (int i = 0; i < php ->size;++i)
    {
        php ->heap[i] = arr[i];
    }
    //寻找最后一个分支的下标
    int cur_pos = n / 2 - 1;
    while (cur_pos >= 0)
    {
        AdjustDown(php,cur_pos);
        cur_pos--;
    }
}
//判断堆是否满了
bool HeapIsFull(Heap *php)
{
    return php ->size >= php ->capacity;
}

//判断堆是否是空
bool HeapIsEmpty(Heap *php)
{
    return php ->size == 0;
}

//向上调整
void AdjustUp(Heap *php,int start)
{
    assert(php);
    int j = start;
    int i = (j - 1) / 2;
    Elemtype tmp = php ->heap[j];
    while (j > 0)
    {
        if (php ->heap[j] < php ->heap[i])
        {
            php ->heap[j] = php ->heap[i];
            j = i;
            i = (j - 1) / 2;
        } else{
            break;
        }
    }
    php ->heap[i] = tmp;
}

//向下调整
void AdjustDown(Heap *php,int start)
{
    assert(php);
    int i = start;//i为父节点
    int j = 2 * i + 1;//j为i节点的左子树
    Elemtype tmp = php ->heap[i];;
    while (j < php ->size)
    {
        //j + 1 < php ->size 是为了表明右子树存在
        if (j + 1 < php ->size && php ->heap[j] > php ->heap[j + 1])
        {
            j = j + 1;
        }
        if (tmp > php ->heap[j])
        {
            php ->heap[i] = php ->heap[j];
            i = j;
            j = 2 * i + 1;
        } else{
            break;
        }
    }
    php ->heap[i] = tmp;
}

//元素插入
void HeapInsert(Heap *php,Elemtype x)
{
    assert(php);
    //判断堆是否满了
    if (HeapIsFull(php))
    {
        printf("heap is full,%d insert error!\n",x);
        return;
    }
    php ->heap[php ->size] = x;
    AdjustUp(php,php ->size);
    php ->size++;
}

//获取堆顶元素
Elemtype HeapTop(Heap *php)
{
    assert(php);
    if (HeapIsEmpty(php))
    {
        printf("the heap is empty!\n");
    }
    return php ->heap[0];
}

//删除堆顶元素
void HeapRemove(Heap *php)
{
    assert(php);
    if (HeapIsEmpty(php))
    {
        printf("the heap is empty!\n");
        return;
    }
    php ->size--;
    php ->heap[0] = php ->heap[php ->size];
    AdjustDown(php,0);
}
//显示
void HeapShow(Heap *php)
{
    assert(php);
    for (int i = 0;i < php ->size;++i)
    {
        printf("%d ",php ->heap[i]);
    }
    printf("\n");
}

//清除
void HeapClear(Heap *php)
{
    php ->size = 0;
}

//摧毁
void HeapDestory(Heap *php)
{
    free(php ->heap);
    php ->heap = NULL;
    php ->size = 0;
    php ->capacity = 0;
}