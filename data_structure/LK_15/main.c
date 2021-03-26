//https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/

//589. N 叉树的前序遍历

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void preorderSearch(struct Node* root,int *arr,int *returnSize)
{
    if (root)
    {
        arr[(*returnSize)++] = root->val;
        for (int i = 0;i < root->numChildren;++i)
            preorderSearch(root->children[i],arr,returnSize);
    }
}
int* preorder(struct Node* root, int* returnSize)
{
    int *arr = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    preorderSearch(root,arr,returnSize);
    return arr;
}
