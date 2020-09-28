//
// Created by 胡杨 on 2020/9/28.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef struct queue
{
    int *pBase;
    int front;
    int rear;
    int maxsize;
}Queue,*PQueue;
void CreateQueue(PQueue Q, int maxsize);
void TraverseQueue(PQueue Q);
bool FullQueue(PQueue Q);
bool EmptyQueue(PQueue Q);
bool EnQueue(PQueue Q,int tmp);
bool DeQueue(PQueue Q,int *tmp);
#endif //QUEUE_QUEUE_H
