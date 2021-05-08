//https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/

//剑指 Offer 54. 二叉搜索树的第k大节点

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//dfs
class Solution {
public:
    void dfs(TreeNode *root,int &res,int &k)
    {
        if (!root)
            return;
        dfs(root->right,res,k);
        if (!(--k))
            res = root->val;
        dfs(root->left,res,k);
    }
public:
    int kthLargest(TreeNode* root, int k)
    {
        int res = 0;
        dfs(root,res,k);
        return res;
    }
};