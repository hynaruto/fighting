
//https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

//107. 二叉树的层序遍历 II

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
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    //开辟二维数组空间
    int **arr = (int**)malloc(sizeof(int*) * Size);
    //定义一个数组用于存放每层的结点个数
    int count = 0,level = 0;
    int countnums[Size] = {0};
    //定义一个队列用于存放结点
    struct TreeNode* queue[Size];
    int front = -1,rear = -1;
    //根结点先入队
    queue[++rear] = root;
    //当队列不为空的时
    while (front != rear)
    {
        //计算每层结点的个数
        count = (rear - front % Size);
        //将结点个数保存在数组
        countnums[level] = count;
        //为每层val开辟空间
        arr[level] = (int*)malloc(sizeof(int) * count);
        //将每层的val存入数组
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
    //将二维数组倒序
    int **res = (int**)malloc(sizeof(int*) * level);
    int k = 0;
    for (int i = level - 1;i >= 0;--i)
    {
        res[k] = arr[i];
        (*returnColumnSizes)[k] = countnums[i];
        k++;
    }
    return res;
}