//https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoo0ts/


//填充每个节点的下一个右侧节点指针


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
#define Size 4096
struct Node* connect(struct Node* root)
{
    if (!root)
        return NULL;
    //int **arr = (int**)malloc(sizeof(int*) * Size);
    int *countarr = (int*)malloc(sizeof(int) * Size);
    int count = 0,level = 0;
    struct Node *queue[Size];
    int rear = -1,front = -1;
    queue[++rear] = root;
    while (rear != front)
    {
        count = (rear - front % Size);
        countarr[level] = count;
        //int *arr = (int*)malloc(sizeof(int) * count);
        struct Node* pre = NULL;
        for (int i = 0;i < count;++i)
        {
            struct Node *p = queue[++front];
            if (pre != NULL)
                pre->next = p;
            pre = p;
            if (p->left)
                queue[++rear] = p->left;
            if (p->right)
                queue[++rear] = p->right;
        }
        level++;
    }
    return root;
}