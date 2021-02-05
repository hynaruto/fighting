//
// Created by 胡杨 on 2021/2/1.
//

#include "Sort.h"

//交换函数
static void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//直接插入排序
void InsertSort_1(int ar[],int left,int right)
{
    for (int i = left + 1;i < right;++i)
    {
        int k = left;
        while (ar[i] < ar[k])
        {
            k++;
        }
        int tmp = ar[i];
        for (int j = i;j > k;--j)
        {
            ar[j] = ar[j - 1];
        }
        ar[k] = tmp;
    }
}

//直接插入排序-从后往前比较
void InsertSort_2(int ar[],int left,int right)
{
    for (int i = left + 1;i < right;++i)
    {
        int j = i;
        while (j > left && ar[j] < ar[j - 1])
        {
            Swap(&ar[j],&ar[j - 1]);
            j--;
        }
    }
}

//直接插入排序-从后往前比较不调用交换函数
void InsertSort_3(int arr[],int left,int right)
{
    for (int i = left + 1;i < right;++i)
    {
        int j = i;
        int tmp = arr[j];
        while (j > left && tmp < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
    }
}

//直接插入排序-哨兵位
void InsertSort_4(int arr[],int left,int right)
{
    for (int i = left + 1;i < right;++i)
    {
        arr[0] = arr[i];
        int j = i;
        while (arr[0] < arr[j - 1])
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = arr[0];
    }
}

//折半插入排序
void BinInsertSort(int arr[], int left, int right)
{
    for (int i = left + 1;i < right;++i)
    {
        int tmp = arr[i];
        int low = left;
        int high = i - 1;
        int mid = 0;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (tmp < arr[mid])
                high = mid - 1;
            if (tmp >= arr[mid])
                low = mid + 1;
        }
        for (int j = i;j > low;--j)
        {
            arr[j] = arr[j - 1];
        }
        arr[low] = tmp;
    }
}

//2路插入排序
void TwoWayInsertSort(int *ar, int left, int right)
{
    int n = right - left;
    int *tmp = (int*)malloc(sizeof(int) * n);

    tmp[0] = ar[left];
    int first, final;
    first = final = 0;

    for(int i=left+1; i<right; ++i)
    {
        if(ar[i] < tmp[first])
        {
            first = (first-1+n) % n;
            tmp[first] = ar[i];
        }
        else if(ar[i] >= tmp[final])
        {
            tmp[++final] = ar[i];
        }
        else
        {
            int end = final;
            while(ar[i] < tmp[end])
            {
                tmp[(end+1)%n] = tmp[end];
                end = (end-1+n) % n;
            }
            tmp[(end+1)%n] = ar[i];
            final++;
        }
    }

    int k = 0;
    for(int i=first; k<n; ++k)
    {
        ar[k] = tmp[i];
        i = (i+1) % n;
    }
    free(tmp);
}

//希尔排序(效率最高)
void ShellSort(int *ar, int left, int right)
{
    //分割
    int gap = right - left;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        for (int i = left + gap;i < right;++i)
        {
            if (ar[i] < ar[i - gap])
            {
                //交换
                int tmp = ar[i];
                int j = i;
                while (j >left && tmp < ar[j - gap])
                {
                    ar[j] = ar[j - gap];
                    j = j - gap;
                }
                ar[j] = tmp;
            }
        }
    }
}

//简单选择排序
static int GetMinIndex(int *arr,int left,int right)
{
    int min_value = arr[left];
    int index = left;
    for (int i = left + 1; i < right;++i)
    {
       if (arr[i] < min_value)
       {
           min_value = arr[i];
           index = i;
       }
    }
    return index;
}
void SelectSort(int *ar, int left, int right)
{
    for (int i = left;i < right - 1;++i)
    {
        int index = GetMinIndex(ar,i,right);
        if (index != i)
        {
            Swap(&ar[i],&ar[index]);
        }
    }
}

//堆排(升序--大堆)
static void AdjustDown(int *ar,int left,int right,int start)
{
    int n =right - left;
    int i = start;
    int j = 2 * i + 1;
    int tmp = ar[i];
    while (j < n)
    {
        if (j + 1 < n && ar[j] < ar[j + 1])
        {
            j = j + 1;
        }
        //找到大的子节点,开始交换
        if (tmp < ar[j])
        {
            ar[i] = ar[j];
            i = j;
            j = 2 * i + 1;
        } else{
            break;
        }
    }
    ar[i] = tmp;
}
void HeapSort(int *ar, int left, int right)
{
    int n = right - left;
    int curpos = n / 2 - 1 + left;
    while (curpos >= 0)
    {
        AdjustDown(ar,left,right,curpos);
        curpos--;
    }
    //开始排序
    int end = right - 1;
    while (end > left)
    {
        Swap(&ar[left],&ar[end]);
        AdjustDown(ar,left,end,0);
        end--;
    }
}

//冒泡排序
void BubbleSort_1(int *arr,int left,int right)
{
    for (int i = left;i < right;++i)
    {
        for (int j = left;j < right - i - 1;++j)
        {
            //交换
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j],&arr[j + 1]);
            }
        }
    }
}

//改进的冒泡排序
void BubbleSort_2(int *arr,int left,int right)
{
    bool is_swap = false;
    for (int i = left;i < right;++i)
    {
        for (int j = left;j < right - i - 1;++j)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j],&arr[j + 1]);
                is_swap = true;
            }
            if (!is_swap)
                break;
            else
                is_swap = true;
        }
    }
}

//快速排序-hoare法
void Partition_1(int *ar,int left,int right)
{
    int low = left;
    int high = right - 1;
    int key = ar[low];
    //找到key的曲轴点，将比key值小的点放在低端，比key值大的点放在高端
    while (low < high && ar[high] > key)
        high--;
    Swap(&ar[low],&ar[high]);
    while (low < high && ar[low] <= key)
        low++;
    Swap(&ar[low],&ar[high]);
}

//快速排序-挖坑法
void Partition_2(int *ar,int left,int right)
{
    int low = left;
    int high = right - 1;
    int key = ar[low];
    while (low < high)
    {
        while (low < right && ar[high] > key)
            high--;
        ar[low] = ar[high];
        while (low < right && ar[low] <= key)
            low++;
        ar[high] = ar[low];
    }
    ar[low] = key;
}

//快速排序-前后指针法
static int GetMidIndex(int *ar,int left,int right)
{
    int mid = (left + right) / 2;
    if (ar[left] > mid && ar[mid] < ar[right - 1])
        return mid;
    if (ar[left] > ar[mid] && ar[left] < ar[right - 1])
        return left;
    return right - 1;
}

int Partition_3(int *ar,int left,int right)
{
    int mid_index = GetMinIndex(ar,0,right);
    if (mid_index != left)
        Swap(&ar[mid_index],&ar[left]);
    int key = ar[left];
    int pos = left;
    for (int i = pos + 1;i < right;++i)
    {
        if (ar[i] < key)
        {
            pos++;
            if (pos != i)
            {
                Swap(&ar[pos],&ar[i]);
            }
        }
    }
    Swap(&ar[left],&ar[pos]);
    return pos;
}

//快速排序
#define M 5
void QuickSort(int *ar,int left,int right)
{
    if (left <= right)
        return;
    if (right - left <= M)
        InsertSort_3(ar,left,right);
    else{
        int pos = Partition_3(ar,left,right);
        QuickSort(ar,left,pos);
        QuickSort(ar,pos + 1,right);
    }
}

//2路归并排序
static void MergeSort_(int *ar,int *tmp,int left,int right)
{
    //分组
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    MergeSort_(ar,tmp,left,mid);
    MergeSort_(ar,tmp,mid+1,right);
    //开始并归
    int begin1,end1,begin2,end2;
    begin1 = left,end1 = mid;
    begin2 = mid + 1,end2 = right;
    int k = left;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (ar[begin1] < ar[begin2])
            tmp[k++] = ar[begin1++];
        else
            tmp[k++] = ar[begin2++];
    }
    //局部并归
    while (begin1 < end1)
        tmp[k++] = ar[begin1++];
    while (begin2 <= end2)
        tmp[k++] = ar[begin2++];
    //拷贝
    memcpy(ar+left,tmp+left, sizeof(int) * (right - left + 1));
}
void MergeSort(int *ar, int left, int right)
{
    int n = right - left;
    int *tmp = (int*)malloc(sizeof(int) * n);
    MergeSort_(ar,tmp,left,right - 1);
    free(tmp);
}

//基数排序
int  GetKey(int value, int k) //2  3
{
    int key;
    while(k >= 0)
    {
        key = value % 10;
        value /= 10;
        k--;
    }
    return key;
}

void Distribute(int *ar, int left, int right, int k)
{
    for(int i=left; i<right; ++i)
    {
        int key = GetKey(ar[i], k);
        SListPushBack(&list[key], ar[i]);
    }
}

void Collect(int *ar)
{
    int k = 0;
    for(int i=0; i<RADIX; ++i)
    {
        SListNode *p = list[i].head;
        while(p != NULL)
        {
            ar[k++] = p->data;
            p = p->next;
        }
    }

    //清除链表
    for(int i=0; i<RADIX; ++i)
        SListClear(&list[i]);
}

void RadixSort(int *ar, int left, int right)
{
    for(int i=0; i<RADIX; ++i)
        SListInit(&list[i]);

    for(int i=0; i<K; ++i)
    {
        //分发
        Distribute(ar, left, right, i);

        //回收
        Collect(ar);
    }
}


//打印数组
void PrintArr(int arr[],int size)
{
    for (int i = 0; i < size;++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}