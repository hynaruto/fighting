//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
#define MAXSIZE 10000
#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
       int val;
       struct TreeNode *left;
       struct TreeNode *right;
};
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    struct TreeNode *queue[MAXSIZE] = {0};
    int head = 0;
    int tail = 0;
    int** res = (int**)malloc(sizeof(int*) * MAXSIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int*) * MAXSIZE);
    queue[tail++] = root;
    *returnSize = 0;
    while(head < tail)
    {
        int size = (tail - head + MAXSIZE) % MAXSIZE;
        (*returnColumnSizes)[*returnSize] = size;
        res[*returnSize] = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size;++i)
        {
            struct TreeNode *tmp = queue[head++];
            res[*returnSize][i] = tmp ->val;
            if (tmp -> left != NULL)
            {
                queue[tail++] = tmp ->left;
            }
            if (tmp ->right != NULL)
            {
                queue[tail++] = tmp ->right;
            }
        }
        (*returnSize)++;
    }
    return res;
}