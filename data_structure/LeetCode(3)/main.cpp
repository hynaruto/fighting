//给定一个二叉树，返回它的 前序 遍历。
//输入: [1,null,2,3]
//1
//\
//    2
// /
//3
//输出: [1,2,3]

#include <cstdlib>
//定义树结构
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
void preorder(struct TreeNode* root,int* ret,int* returnSize)
{
    if (root)
    {
        ret[*(returnSize)++] = root ->val;
        preorder(root ->left,ret,returnSize);
        preorder(root ->right,ret,returnSize);
    }
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    int* ret = (int*)malloc(100 * sizeof(int));
    preorder(root,ret,returnSize);
    return ret;
}