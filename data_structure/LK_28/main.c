//https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xm5go5/


//将有序数组转换为二叉搜索树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if (NULL == nums || 0 == numsSize)
        return NULL;
    int Mid = numsSize / 2;
    //给树开辟空间
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[Mid];
    root->left = sortedArrayToBST(nums,Mid);
    root->right = sortedArrayToBST(nums + Mid + 1,numsSize - Mid - 1);
    return root;
}