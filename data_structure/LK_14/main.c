//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnv1oc/

//回文链表

//解1:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *FindMid(struct ListNode *head)
{
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast ->next && fast ->next ->next)
    {
        fast = fast ->next->next;
        slow = slow ->next;
    }
    return slow;
}
struct ListNode *Reverse(struct ListNode *head)
{
    if (NULL == head || NULL == head ->next)
        return head;
    struct ListNode *p = head ->next;
    struct ListNode *q = NULL;
    head ->next = NULL;
    while (p)
    {
        q = p->next;
        p ->next = head;
        head = p;
        p = q;
    }
    return head;
}
bool isPalindrome(struct ListNode* head)
{
    //用快慢指针找到链表中点
    //将中点之前的链表部分反转
    //判断前后是否相等
    if (NULL == head)
        return true;
    struct ListNode *p = FindMid(head);
    struct ListNode *q = Reverse(p ->next);

    struct ListNode *m = head;
    struct ListNode *n = q;
    bool result  = true;

    while(result && n)
    {
        if (m ->val != n ->val)
            result = false;
        m = m ->next;
        n = n ->next;
    }
    //还原链表
    //p ->next = Reverse(q);
    return result;
}

//解2:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head)
{
    //把链表中的值存入数组中，再比较
    struct ListNode *p = head;
    int size = 0;
    int arr[500000] = {0};
    while (p)
    {
        if (p)
        {
            arr[size++] = p ->val;
        }
        p = p->next;
    }
    int start = 0,end = size - 1;
    for (int i = 0;i < size;++i)
    {
        if (arr[start++] != arr[end--])
            return false;
    }
    return true;
}