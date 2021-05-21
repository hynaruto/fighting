//606. 根据二叉树创建字符串

//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//
//空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <string>
#include <vector>
using namespace std;
class Solution;
class TreeNode
{
    friend class Solution;
public:
    explicit TreeNode():val(0),left(nullptr),right(nullptr)
    {}
    explicit TreeNode(int x):val(x),left(nullptr),right(nullptr)
    {}
    explicit TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right)
    {}
    ~TreeNode() = default;
private:
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    string tree2str(TreeNode* root)
    {
        if (!root)
            return "";
        if (!root->left && !root->right)
            return to_string(root->val);
        if (!root->right)
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        return to_string(root->val) + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }
};
