//https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpcnds/

//删除二叉搜索树中的节点

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
static struct TreeNode* GetMin(struct TreeNode* root)
{
    while (root->left)
        root = root->left;
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if (!root)
        return NULL;
    if (root->val == key)
    {
        //如果要删的结点只有一个左叶子结点或者右叶子结点
        if (root->left == NULL)
            return root->right;
        if (root->right == NULL)
            return root->left;
        //如果要删除的结点有2个子结点,找到左子树最大的val，或者右子树最小的val,替换key
        struct TreeNode* MinNode = GetMin(root->right);
        root->val = MinNode->val;
        root->right = deleteNode(root->right,MinNode->val);
    }else if (root->val > key)
    {
        root->left = deleteNode(root->left,key);
    }else if (root->val < key)
    {
        root->right = deleteNode(root->right,key);
    }
    return root;
}