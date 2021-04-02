//https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xmx4r7/


//平衡二叉树


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int GetPath(struct TreeNode* root)
{
    if (!root)
        return true;
    int left_depth = GetPath(root->left);
    int right_depth = GetPath(root->right);
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}

bool isBalanced(struct TreeNode* root)
{
    if (!root)
        return true;
    int left_depth = GetPath(root->left);
    int right_depth = GetPath(root->right);
    return (abs(left_depth - right_depth) < 2) && isBalanced(root->left) && isBalanced(root->right);
}