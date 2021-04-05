//https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xo566j/

//路径总和

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum)
{
    if (!root)
        return false;
    if (root->left == NULL && root->right == NULL && targetSum - root->val == 0)
        return true;
    return hasPathSum(root->left,targetSum - root->val) || hasPathSum(root->right,targetSum - root->val);
}