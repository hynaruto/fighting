//https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/submissions/

//637. 二叉树的层平均值


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
double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    /*
    if (!root)
    {
        *returnSize = 0;
        retrun NULL;
    }
    */
    int **arr= (int**)malloc(sizeof(int*) * Size);
    //保存每层结点的个数
    int *countarr = (int*)malloc(sizeof(int) * Size);
    int count = 0,level = 0;
    //定义队列
    struct TreeNode* queue[Size];
    int front = -1,rear = -1;
    //根结点入队
    queue[++rear] = root;
    double *result = (double*)malloc(sizeof(double) * Size);
    while (front != rear)
    {
        count = (rear - front % Size);
        countarr[level] = count;
        //为每层结点保存val开辟空间
        arr[level] = (int*)malloc(sizeof(int) * count);
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
    double sum = 0;
    for (int i = 0;i < level;++i)
    {
        for(int j = 0;j < countarr[i];++j)
        {
            sum += arr[i][j];
        }
        result[i] = sum / countarr[i];
        sum = 0;
    }
    *returnSize = level;
    return result;
}