//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnldjj/

//二叉树的层序遍历

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
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    //申请一个二维数组
    int **arr = (int**)malloc(sizeof(int*) * Size);
    //申请*returnColumnSizes的空间，用来存放每层结点的个数
    *returnColumnSizes = (int*)malloc(sizeof(int) * Size);
    //定义整形变量用于记录每层结点的个数
    int level = 0,count = 0;
    //定义队列
    struct TreeNode* queue[Size];
    int front = -1,rear = -1;
    queue[++rear] = root;
    //当队列不为空的时候
    while (front != rear)
    {
        //计算第0层结点的个数
        count = (rear - front % Size);
        (*returnColumnSizes)[level] = count;
        //给第0层开辟空间
        arr[level] = (int*)malloc(sizeof(int) * count);
        //开始把第0层的val入队
        for (int i = 0;i < count;++i)
        {
            struct TreeNode* p = queue[++front];
            arr[level][i] = p->val;
            if (p->left)
                queue[++rear] = p->left;
            if (p->right)
                queue[++rear] = p->right;
        }
        level++;
    }
    *returnSize = level;
    return arr;
}