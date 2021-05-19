//105. 从前序与中序遍历序列构造二叉树

//https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
class Solution;
class TreeNode
{
    friend class Solution;
public:
    TreeNode():val(0),left(nullptr),right(nullptr)
    {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr)
    {}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right)
    {}
private:
    TreeNode *left;
    TreeNode *right;
    int val;
};
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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i = 1; i < preorder.size(); ++i) {
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};

/*
class Solution{
public:
   unordered_map<int,int> map;
public:
   TreeNode *helper(vector<int>& preorder, vector<int>& inorder,int preorder_left,int preorder_right,int inorder_left,int inorder_right)
   {
       if (preorder_right < preorder_left)
           return nullptr;
       //前序的第一个结点为根结点
       //根据根结点找到中序根结点的索引
       int preorder_root = preorder_left;
       int inorder_root = map[preorder[preorder_root]];
       //建立根
       TreeNode *root = new TreeNode(preorder[preorder_root]);
       //left
       int left_size = inorder_root - inorder_left;
       root->left = helper(preorder,inorder,preorder_left + 1,preorder_left + left_size,inorder_left,inorder_root - 1);
       //right
       root->right = helper(preorder,inorder,preorder_left + 1,preorder_right,inorder_root + 1,inorder_right);
       return root;
   }
public:
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
   {
       int size = preorder.size();
       for (int i = 0;i < size;++i)
           map[inorder[i]] = i;
       return helper(preorder,inorder,0,size - 1,0,size - 1);

   }
};
*/