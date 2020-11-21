//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
int* reversePrint(struct ListNode* head, int* returnSize)
{
    if (head == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    struct ListNode *p = head;
    int num = 0;
    while (p != NULL)
    {
        p = p ->next;
        num++;
    }
    int *ret = (int*)malloc(sizeof(int) * num);
    for (int i = 0;i < num;++i)
    {
        ret[num - 1 - i] = head ->val;
        head = head ->next;
    }
    *returnSize = num;
    return ret;
}