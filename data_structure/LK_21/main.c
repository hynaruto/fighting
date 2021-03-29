//https://leetcode-cn.com/problems/find-bottom-left-tree-value/submissions/

//513. 找树左下角的值


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define Size 10000
int findBottomLeftValue(struct TreeNode* root)
{
    //定义一个数组用于保存每层结点的个数
    int countnums[Size] = {0};
    int **arr = (int**)malloc(sizeof(int*) * Size);
    int count = 0,level = 0;
    //定义队列用于存放结点
    struct TreeNode* queue[Size];
    int front = - 1,rear = -1;
    queue[++rear] = root;
    //当队列不为空的时候
    while (front != rear)
    {
        level++;
        count = (rear - front % Size);
        countnums[level] = count;
        arr[level] = (int*)malloc(sizeof(int*) * count);
        for (int i = 0;i < count;++i)
        {
            struct TreeNode* p = queue[++front];
            arr[level][i] = p->val;
            if (p->left)
                queue[++rear] = p->left;
            if (p->right)
                queue[++rear] = p->right;
        }
    }
    return arr[level][0];
}