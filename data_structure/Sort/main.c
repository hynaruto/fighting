#include "Sort.h"

int main()
{
    int ar[] = {11,12,35,36,44,37,22,43,87,99,67};
    int n = sizeof(ar) / sizeof(ar[0]);
    //直接插入排序
    InsertSort_1(ar,0,n);
    PrintArr(ar,n);
    //直接插入排序-从后往前比较（交换数据）
    InsertSort_2(ar,0,n);
    PrintArr(ar,n);
    //直接插入排序-从后往前比较不调用交换函数
    InsertSort_3(ar,0,n);
    PrintArr(ar,n);
    //直接插入排序-哨兵位置
    //InsertSort_4(ar,1,n);
    //PrintArr(ar,n);
    //折半插入排序
    BinInsertSort(ar,0,n);
    PrintArr(ar,n);
    //2路插入排序
    TwoWayInsertSort(ar,0,n);
    PrintArr(ar,n);
    //希尔排序
    ShellSort(ar,0,n);
    PrintArr(ar,n);
    //简单选择排序
    SelectSort(ar,0,n);
    PrintArr(ar,n);
    //堆排
    HeapSort(ar,0,n);
    PrintArr(ar,n);
    //冒泡排序
    BubbleSort_1(ar,0,n);
    PrintArr(ar,n);
    //改进的冒泡排序
    BubbleSort_2(ar,0,n);
    PrintArr(ar,n);
    //快速排序-hoare法
    Partition_1(ar,0,n);
    PrintArr(ar,n);
    //快速排序-挖坑法
    Partition_2(ar,0,n);
    PrintArr(ar,n);
    //快速排序-前后指针法
    Partition_3(ar,0,n);
    PrintArr(ar,n);
    //快速排序
    QuickSort(ar,0,n);
    PrintArr(ar,n);
    //归并排序
    MergeSort(ar,0,n);
    PrintArr(ar,n);
    //基数排序
    RadixSort(ar,0,n);
    PrintArr(ar,n);
    return 0;
}
