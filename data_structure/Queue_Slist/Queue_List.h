//
// Created by 胡杨 on 2021/1/24.
//

#ifndef QUEUE_SLIST_QUEUE_LIST_H
#define QUEUE_SLIST_QUEUE_LIST_H

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



#define QueueElemType int

typedef struct LinkQueueNode
{
    QueueElemType data;
    struct LinkQueueNode *next;
}LinkQueueNode;

typedef struct LinkQueue
{
    LinkQueueNode *head;
    LinkQueueNode *tail; //指向队尾节点
}LinkQueue;

void LinkQueueInit(LinkQueue *pq);
void LinkQueueDestroy(LinkQueue *pq);
void LinkQueueEn(LinkQueue *pq, QueueElemType x);
void LinkQueueDe(LinkQueue *pq);
void LinkQueueShow(LinkQueue *pq);
QueueElemType LinkQueueBack(LinkQueue *pq);
QueueElemType LinkQueueFront(LinkQueue *pq);

void LinkQueueInit(LinkQueue *pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}

void LinkQueueEn(LinkQueue *pq, QueueElemType x)
{
    assert(pq);
    LinkQueueNode *s = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    assert(s != NULL);
    s->data = x;
    s->next = NULL;
    if(pq->head == NULL)
        pq->head = pq->tail = s;
    else
    {
        pq->tail->next = s;
        pq->tail = s;
    }
}

void LinkQueueDe(LinkQueue *pq)
{
    assert(pq);
    if(pq->head != NULL)
    {
        LinkQueueNode *p = pq->head;
        pq->head = p->next;
        if(pq->head == NULL)
            pq->tail = NULL;
        free(p);
    }
}

void LinkQueueShow(LinkQueue *pq)
{
    assert(pq != NULL);
    LinkQueueNode *p = pq->head;
    while(p != NULL)
    {
        printf("%d<--", p->data);
        p = p->next;
    }
    printf("Nil.\n");
}

QueueElemType LinkQueueBack(LinkQueue *pq)
{
    assert(pq && pq->head);
    return pq->tail->data;
}
QueueElemType LinkQueueFront(LinkQueue *pq)
{
    assert(pq && pq->head);
    return pq->head->data;
}

void LinkQueueDestroy(LinkQueue *pq)
{
    assert(pq);
    while(pq->head != NULL)
    {
        LinkQueueNode *p = pq->head;
        pq->head = p->next;
        free(p);
    }
    pq->head = pq->tail = NULL;
}


#endif //QUEUE_SLIST_QUEUE_LIST_H
