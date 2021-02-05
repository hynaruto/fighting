//
// Created by 胡杨 on 2021/2/1.
//

#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void InsertSort_1(int ar[],int left,int right);
void InsertSort_2(int arr[],int left,int right);
void InsertSort_3(int arr[],int left,int right);
void InsertSort_4(int arr[],int left,int right);
void BinInsertSort(int *ar, int left, int right);
void TwoWayInsertSort(int *ar, int left, int right);
void ShellSort(int *ar, int left, int right);
void SelectSort(int *arr,int left,int right);
void HeapSort(int *arr,int left,int right);
void BubbleSort_1(int *arr,int left,int right);
void BubbleSort_2(int *arr,int left,int right);
void Partition_1(int *ar,int left,int right);
void Partition_2(int *ar,int left,int right);
int Partition_3(int *ar,int left,int right);
void QuickSort(int *ar,int left,int right);
void MergeSort(int *ar, int left, int right);
void RadixSort(int *ar, int left, int right);
void PrintArr(int arr[],int size);


#endif //SORT_SORT_H
