//106. 从中序与后序遍历序列构造二叉树

//https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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


#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;
class Solution;
class TreeNode{
    friend class Solution;
public:
    TreeNode():val(0),left(nullptr),right(nullptr)
    {}
    TreeNode(int x,TreeNode *left,TreeNode *right) : val(x),left(left),right(right)
    {}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr)
    {}
    ~TreeNode() = default;
private:
    int val;
    TreeNode *left;
    TreeNode *right;
};

//迭代版本
//用一个栈和一个指针辅助进行二叉树的构造。
// 初始时栈中存放了根节点（后序遍历的最后一个节点），指针指向中序遍历的最后一个节点；
//依次枚举后序遍历中除了第一个节点以外的每个节点。
//如果 index 恰好指向栈顶节点，那么我们不断地弹出栈顶节点并向左移动 index，并将当前节点作为最后一个弹出的节点的左儿子；
// 如果 index 和栈顶节点不同，我们将当前节点作为栈顶节点的右儿子；
//无论是哪一种情况，最后都将当前的节点入栈。
class Solution
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0)
            return nullptr;
        auto *root = new TreeNode(postorder[postorder.size() - 1]);
        stack<TreeNode *> s = stack<TreeNode*>();
        s.push(root);
        int inorder_inedx = inorder.size() - 1;
        for (int i = (int)postorder.size() - 2;i >= 0;--i)
        {
            int postorder_val = postorder[i];
            auto node = s.top();
            if (node->val != inorder[inorder_inedx])
            {
                node->right = new TreeNode(postorder_val);
                s.push(node->right);
            }else{
                while (!s.empty() && s.top()->val == inorder[inorder_inedx])
                {
                    node = s.top();
                    s.pop();
                    inorder_inedx--;
                }
                node->left = new TreeNode(postorder_val);
                s.push(node->left);
            }
        }
        return root;
    }
};
/*
//递归版本
class Solution {
public:
    int p_index;//后续遍历的下标
    unordered_map<int,int> map;
public:
    TreeNode *helper(int left,int right,vector<int>& inorder, vector<int>& postorder)
    {
        if (left > right)
            return nullptr;
        //找到后续遍历的最后一个结点---根结点
        int val = postorder[p_index];
        TreeNode *root = new TreeNode(val);
        int index = map[val];
        p_index--;
        root->right = helper(index + 1,right,inorder,postorder);
        root->left = helper(left,index - 1,inorder,postorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        p_index = (int)postorder.size() - 1;
        int k = 0;
        for (auto &e : inorder)
            map[e] = k++;
        return helper(0,(int)inorder.size() - 1,inorder,postorder);
    }

private:
    TreeNode *root;
};
*/