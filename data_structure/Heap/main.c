#include "Heap.h"
int main()
{
    Heap hp;
    Elemtype arr[] = {27,15,19,18,28,34,65,49,25,37};
    int n = sizeof(arr) / sizeof(arr[0]);
    HeapInit(&hp,20);
    HeapInitByArr(&hp,arr,n);
    for (int i = 0; i < n;++i)
    {
        //插入元素
        HeapInsert(&hp,arr[i]);
    }
    HeapShow(&hp);
    while (!HeapIsEmpty(&hp))
    {
        Elemtype top = HeapTop(&hp);
        printf("%d ",top);
        HeapRemove(&hp);
    }
    printf("\n");
    return 0;
}