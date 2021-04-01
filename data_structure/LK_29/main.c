//https://leetcode-cn.com/problems/count-complete-tree-nodes/submissions/

//222. 完全二叉树的节点个数

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int countNodes(struct TreeNode* root)
{
    struct TreeNode *l = root;
    struct TreeNode *r = root;
    //分别计算左右子树的高度
    int left_high = 0,right_high = 0;
    while (l)
    {
        l = l->left;
        left_high++;
    }
    while (r)
    {
        r = r->right;
        right_high++;
    }
    //当左右子树高度相等的时候是一颗满二叉树
    if (left_high == right_high)
        return pow(2,left_high) - 1;
    //如果左右子树高度不相等，按照普通二叉树计算
    return countNodes(root->left) + countNodes(root->right) + 1;
}