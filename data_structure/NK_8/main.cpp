//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

#include <vector>
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
    int val;
    TreeNode *left;
    TreeNode *right;
};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree)
            return nullptr;
        dfs(pRootOfTree);
        head->left = pre;
        pre->right = head;
        return head;
    }
protected:
    TreeNode *head,*pre;
    void dfs(TreeNode *cur)
    {
        if (!cur)
            return;
        dfs(cur->left);
        if (pre)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};
int main()
{
    Solution S;
    return 0;
}