#include <stdio.h>
#include <cstdlib>
#include "Queue.h"

//初始化队列
void CreateQueue(PQueue Q, int maxsize)
{
    Q ->pBase = (int *)malloc(sizeof(int)*maxsize);
    if (Q ->pBase == NULL)
    {
        printf("初始化队列失败");
        return;
    }
    Q -> front = 0;
    Q -> rear = 0;
    Q -> maxsize = maxsize;
}

//遍历队列
void TraverseQueue(PQueue Q)
{
    int i = Q ->front;
    printf("队列中的元素是:\n");
    while (i % Q ->maxsize != Q ->rear)
    {
        printf("%d",Q ->pBase[i]);
        i = (i + 1) % Q ->maxsize;
    }
    printf("\n");
}

//判断队列是否满
bool FullQueue(PQueue Q)
{
    if ((Q ->rear + 1) % Q ->maxsize == Q ->front)
    {
        return true;
    } else{
        return false;
    }
}

//判断队列为空
bool EmptyQueue(PQueue Q)
{
    if (Q->front == Q->rear)
    {
        return true;
    } else{
        return false;
    }
}

//元素进入队列
bool EnQueue(PQueue Q,int tmp)
{
    if (FullQueue(Q))
    {
        return false;
    } else{
        Q ->pBase[Q ->rear] = tmp;
        Q ->rear = (Q ->rear + 1) % Q ->maxsize;
        return true;
    }
}

//删除队列中的元素
bool DeQueue(PQueue Q,int *tmp)
{
    if (EmptyQueue(Q))
    {
        return false;
    } else{
        *tmp = Q ->pBase[Q ->front];
        Q ->front = (Q ->front + 1) % Q ->maxsize;
        return true;
    }
}
 int main()
 {
     return 0;
 }