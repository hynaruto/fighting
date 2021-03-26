//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn2925/

//删除链表的倒数第N个节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    //快慢指针
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    for (int i = 0;i < n;++i)
    {
        fast = fast ->next;
    }
    if (fast == NULL)
    {
        //表明要删除的是头节点
        return head ->next;
    }
    //让slow和fast一起移动
    while (fast ->next != NULL)
    {
        slow = slow ->next;
        fast = fast ->next;
    }
    //表明slow走到了要删除结点的前一个结点
    slow ->next = slow ->next ->next;
    return head;
}