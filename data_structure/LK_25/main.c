//https://leetcode-cn.com/problems/validate-binary-search-tree/submissions/

//98. 验证二叉搜索树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isBst(struct TreeNode* root,struct TreeNode* min,struct TreeNode* max)
{
    if (!root)
        return true;
    if (min!=NULL && root->val <= min->val)
        return false;
    if (max!=NULL && root->val >= max->val)
        return false;
    return isBst(root->left,min,root)&&isBst(root->right,root,max);
}

bool isValidBST(struct TreeNode* root)
{
    return isBst(root,NULL,NULL);
}