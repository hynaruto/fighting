//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnnhm6/

//反转链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    if (NULL == head || NULL == head ->next)
        return head;

    struct ListNode *p = head ->next;
    struct ListNode *q = NULL;
    //切割
    head ->next = NULL;
    //头插
    while (p)
    {
        q = p ->next;
        p ->next = head;
        head = p;
        p = q;
    }
    return head;
}