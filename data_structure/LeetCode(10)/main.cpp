 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    if (l1 ->val < l2 ->val)
    {
        head = l1;
        tail = l2;
    }else{
        head = l2;
        tail = l1;
    }
    //定义一个返回指针
    struct ListNode *ret = head;
    struct ListNode *p = NULL;
    while (head ->next != NULL && tail != NULL)
    {
        if (tail ->val <= head ->next ->val)
        {
            p = tail->next;
            tail ->next = head ->next;
            head ->next = tail;
            tail = p;
            head = head ->next;
        }else{
            head = head ->next;
        }
    }  
    if (head ->next == NULL)
    {
       head ->next = tail; 
    }
    return ret;
       
}
