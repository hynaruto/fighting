//
// Created by 胡杨 on 2021/1/17.
//

#include"SeqList.h"


//初始化顺序表
void InitSeqList(SeqList *p)
{
    assert(p);
    p ->base = (ELEMTYPE*)malloc(sizeof(ELEMTYPE) * List_Size);
    if ((p ->base) != NULL)
    {
        printf("Init successful!\n");
        memset(p ->base,0, sizeof(ELEMTYPE) * List_Size);
        p ->capacity = List_Size;
        p ->size = 0;
    } else{
        printf("Init error!\n");
    }
}

//显示顺序表
void SeqListShow_List(SeqList *p)
{
    assert(p);
    for (int i = 0;i < p ->size;++i)
    {
        printf("%d ",p ->base[i]);
    }
    printf("\n");
}
//判断顺序表是否为空
static bool IsEmpty(SeqList *p)
{
    assert(p);
    return (p ->size == 0);
}

//判断顺序表是否满了
static int IsFull(SeqList *p)
{
    assert(p);
    if (p ->size >= p ->capacity )
    {
        printf("the list is full!\n");
    }
}

//给顺序表扩容
static bool Inc (SeqList *p)
{
    assert(p);
    ELEMTYPE *newbase = (ELEMTYPE*)realloc(p ->base, sizeof(ELEMTYPE) * (p ->capacity + INC));
    if (*newbase != NULL)
    {
        printf("realloc successful!\n");
        p ->base = newbase;
        p ->capacity += INC;
        return true;
    } else{
        printf("realloc error!\n");
        return false;
    }
}

//尾部插入
void SeqListPush_back(SeqList *p,ELEMTYPE x)
{
    assert(p);
    //判断顺序表是否满了，如果满了则扩容
    if (!(IsFull(p)) || Inc(p))
    {
        p ->base[p ->size++] = x;
    }
}

//头部插入
void SeqListPush_front(SeqList *p,ELEMTYPE x)
{
    assert(p);
    //判断顺序表是否满了，如果满了则扩容
    if (!(IsFull(p)) || (Inc(p)))
    {
        for (int i = p ->size;i > 0;--i)
        {
            p ->base[i] = p ->base[i - 1];
        }
        p ->base[0] = x;
        p ->size++;
    } else{
        printf("pushfront error!\n");
    }
}

//从尾部删除
void SeqListPop_back(SeqList *p)
{
    assert(p);
    if (IsEmpty(p))
    {
        printf("the list is emty!\n");
    } else{
        p ->size--;
    }
}

//从头部删除
void SeqListPop_front(SeqList *p)
{
    assert(p);
    if (IsEmpty(p))
    {
        printf("the list is empty!\n");
    } else{
        for (int i = 0; i < p ->size - 1;++i)
        {
            p ->base[i] = p ->base[i + 1];
        }
        p ->size--;
    }
}

//求顺序表的长度
int SeqList_length(SeqList *p)
{
    assert(p);
    printf("当前顺序表的长度为:%d\n",p ->size);
    return 0;
}

//求顺序表的容量
int SeqList_capacity(SeqList *p)
{
    assert(p);
    printf("当前顺序表的容量为:%d\n", p ->capacity);
    return 0;
}

//指定位置插入元素
size_t SeqListInsert_pos(SeqList *p,ELEMTYPE pos,ELEMTYPE key)
{
    assert(p);
    //判断插入的位置是否合法
    if (pos < 0 || pos > p ->size)
    {
        printf("error!\n");
    } else if (!(IsFull(p)) || (Inc(p)))
    {
        printf("please enter pos:\n");
        scanf("%d",&pos);
        for (int i = p ->size;i >pos;--i)
        {
            p ->base[i] = p ->base[i - 1];
        }
        printf("please enter the item:\n");
        scanf("%d",&key);
        p ->base[pos] = key;
        p ->size++;
    }
}

//删除顺序表中指定的元素
void SeqListDelect_pos(SeqList *p ,ELEMTYPE pos)
{
    assert(p);
    //判断删除元素位置的有效性
    if (pos < 0 || pos > p ->size)
    {
        printf("the pos is error!\n");
    } else{
        int x = 0;
        printf("please enter the delect x：\n",&x);
        pos = SeqListFind(p,x);
        for (int i = pos;i < p ->size;++i)
        {
            p ->base[i] = p ->base[i + 1];
        }
        p ->size--;
    }
}

//查找顺序表中的元素
int SeqListFind(SeqList *p,ELEMTYPE key)
{
    assert(p);
    for (int i = 0;i < p ->size;++i)
    {
        if (p ->base[i] == key)
        {
            printf("the key's pos is %d\n",i);
        }
    }
}

//排序
void SeqListSort(SeqList *p)
{
    assert(p);
    for (int i = 0;i < p ->size - 1;++i)
    {
        for (int j = 0;j < p ->size - i - 1;++j)
        {
            ELEMTYPE tmp = p ->base[j];
            p ->base[j] = p ->base[j + 1];
            p ->base[j + 1] = tmp;
        }
    }
}

//清空顺序表
void SeqListClear(SeqList *p)
{
    assert(p);
    p ->size = 0;
    if ((p ->size) == 0)
    {
        printf("Clear successful!\n");
    } else{
        printf("Clear error!\n");
    }
}

//顺序表的反转
void SeqListReverse(SeqList *p)
{
    assert(p);
    int start = 0;
    int end = p ->size - 1;
    while (start < end)
    {
        ELEMTYPE tmp = p ->base[start];
        p ->base[end] = p ->base[start];
        p ->base[end] = tmp;
        start++,end--;
    }
}

//删除一个顺序表中特定的所有元素
void SeqListRemove_All(SeqList *p,ELEMTYPE key)
{
    assert(p);
    if (IsEmpty(p))
    {
        printf("the list is empty!\n");
    } else{
        int index,key = 0;
        printf("please enter the item:\n");
        scanf("%d",&key);
        do{
            index = SeqListFind(p,key);
            if (index == -1)
                break;
            SeqListDelect_pos(p,key);
        }while (1);
    }
}