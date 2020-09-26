//单链表的反转
#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

//定义链表节点
struct ListNode
{
    int value;
    ListNode *next;
};

//插入一个新节点到链表中（放在链表头部）
void CreateList(ListNode * & head,int date)
{
    ListNode * p = (ListNode*)malloc(sizeof(ListNode));
    p ->value = date;
    p ->next = NULL;

    if (head == NULL)
    {
        head = p;
        return;
    }
    p ->next = head;
    head = p;
}

void printList(ListNode * head)
{
    ListNode * p = head;
    while (p != NULL)
    {
        cout <<p ->value << " ";
        p = p ->next;
    }
    cout << endl;
}

int main()
{
    int i = 0;
    ListNode * head = NULL;
    for (int i  = 0;i < 9;i++)
    {
        CreateList(head,i);
    }
    printList(head);
    return 0;
}