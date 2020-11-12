//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head ->next == NULL)
    {
        return head;
    }
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;
    while (head != NULL)
    {
        next = head ->next;
        head ->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

