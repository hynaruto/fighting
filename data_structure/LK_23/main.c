//https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/submissions/


//515. 在每个树行中找最大值

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define Size 10000
int* largestValues(struct TreeNode* root, int* returnSize)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    int count =0,level = 0;
    int *res = (int*)malloc(sizeof(int) * Size);
    struct TreeNode *queue[Size];
    int front = -1,rear = -1;
    queue[++rear] = root;
    while (rear != front)
    {
        long int Max = -1e15;
        count = (rear - front % Size);
        for (int i = 0;i < count;++i)
        {
            struct TreeNode *p = queue[++front];
            if (p->left)
                queue[++rear] = p->left;
            if (p->right)
                queue[++rear] = p->right;
            if (p->val > Max)
                Max = p->val;
        }
        res[level++] = Max;
    }
    *returnSize = level;
    return res;
}