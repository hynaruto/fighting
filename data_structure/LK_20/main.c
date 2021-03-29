//https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/submissions/

//103. 二叉树的锯齿形层序遍历


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define Size 10000
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    int **arr = (int**)malloc(sizeof(int*) * Size);
    *returnColumnSizes = (int*)malloc(sizeof(int) * Size);
    int count = 0,level = 0;
    int fornt = -1,rear = -1;
    struct TreeNode *queue[Size];
    queue[++rear] = root;
    while (fornt != rear)
    {
        count = (rear - fornt % Size);
        (*returnColumnSizes)[level] = count;
        arr[level] = (int*)malloc(sizeof(int) * count);
        for (int i = 0;i < count;++i)
        {
            struct TreeNode* p = queue[++fornt];
            arr[level][i] = p->val;
            if (p->left)
                queue[++rear] = p->left;
            if (p->right)
                queue[++rear] = p->right;
        }
        level++;
    }
    *returnSize = level;
    //奇数层的val交换
    for (int i = 0;i < level;i++)
    {
        if (i % 2 != 0)
        {
            int nums = (*returnColumnSizes)[i];
            for (int j = 0;j < nums / 2;++j)
            {
                int tmp = arr[i][j];
                arr[i][j] = arr[i][nums - 1 - j];
                arr[i][nums - 1 - j] = tmp;
            }
        }
    }
    return arr;
}