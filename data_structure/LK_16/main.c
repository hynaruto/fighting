//https://leetcode-cn.com/problems/rotate-list/submissions/

//61. 旋转链表



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (NULL == head || NULL == head ->next)
        return head;
    int count = 1;
    struct ListNode *cur = head;
    while (cur->next)
    {
        count++;
        cur = cur->next;
    }
    cur->next = head;
    cur = head;
    if (k >= count)
        k %= count;
    for (int i = 1;i < count-k;++i)
        cur = cur->next;
    head = cur->next;
    cur->next = NULL;
    return head;
}