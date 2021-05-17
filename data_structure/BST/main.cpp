#include <iostream>
#include <vector>
using namespace std;

template <class _Ty>
class BSTree;
template <class _Ty>
class BSTNode
{
public:
    friend class BSTree<_Ty>;
    BSTNode():_data(_Ty()),left(nullptr),right(nullptr)
    {}
    explicit BSTNode(_Ty val,BSTNode *_left = nullptr,BSTNode *_right = nullptr):_data(val),left(_left),right(_right)
    {}
    ~BSTNode() = default;
private:
    _Ty _data;
    BSTNode *left;
    BSTNode *right;
};

template <class _Ty>
class BSTree
{
public:
    BSTree():root(nullptr)
    {}
    explicit BSTree(vector<_Ty> &nums) : root(nullptr)
    {
        for (auto &e : nums)
            Insert(e);
    }
public:
    bool Insert(const _Ty &key)
    {
        return Insert(root,key);
    }
    bool Remove(const _Ty &key)
    {return Remove(root,key);}
    BSTNode<_Ty>*LMax()const
    {return LMax(root);}
    BSTNode<_Ty> *RMin()const
    {return RMin(root);}
    BSTNode<_Ty> *Search(const _Ty &key)const
    {return Search(root,key);}
    BSTNode<_Ty> *Parent(BSTNode<_Ty> *key)const
    {return Parent(root,key);}
    void Order()
    {Order(root);}
protected:
    bool Insert(BSTNode<_Ty> *&t,int x)
    {
        if (!t)
        {
            t = new BSTNode<_Ty>(x);
            return true;
        }
        if (t->_data < x)
            return Insert(t->right,x);
        else if (t->_data > x)
            return Insert(t->left,x);
        else
            return false;
    }
    bool Remove(BSTNode<_Ty> *&t,const int &key)
    {
        if (!t)
            return false;
        if (t->_data < key)
            return Remove(t->right,key);
        else if (t->_data > key)
            return Remove(t->left,key);
        else
        {
            BSTNode<_Ty> *p = nullptr;
            //找到了，开始删除
            if (!t->left && !t->right)
            {
                p = t->left;
                LMax(p);
                t->_data = p->_data;
                Remove(t->left,p->_data);
            }else
            {
                p = t;
                if (t->left)
                    t = t->left;
                else
                    t = t->right;
                delete p;
            }
        }
        return true;
    }
    void Order(BSTNode<_Ty> *t)const
    {
        if (t)
        {
            Order(t->left);
            cout<<t->_data<<" ";
            Order(t->right);
        }
    }
    BSTNode<_Ty> *Parent(BSTNode<_Ty> *t,BSTNode<_Ty> *key)const
    {
        if (!t || key = t)
            return nullptr;
        if (key == t->left || key == t->right)
            return t;
        if (key->_data < t->_data)
            return Parent(t->left,key);
        else if (key->_data > t->_data)
            return Parent(t->right,key);
    }
    BSTNode<_Ty> *Search(BSTNode<_Ty> *t,const _Ty &key)const
    {
        if (!t)
            return nullptr;
        if (t->_data < key)
            return Search(t->right,key);
        else if (t->_data > key)
            return Search(t->left,key);
        return t;
    }
    BSTNode<_Ty> *LMax(BSTNode<_Ty> *t)const
    {
        while (t && t->right)
            t = t->right;
        return t;
    }
    BSTNode<_Ty> *RMin(BSTNode<_Ty> *t)const
    {
        while (t &&t->left)
            t = t->left;
        return t;
    }
private:
    BSTNode<_Ty> *root;
};
int main()
{
    vector<int>nums{5,3,4,1,7,8,2,6,0,9};
    BSTree<int> bst(nums);
    bst.Insert(10);
    bst.Remove(4);
    return 0;
}





/*
template<class K, class V>
class BSTree;
template<class K, class V>
class BSTreeNode
{
public:
    friend class BSTree<K,V>;
    BSTreeNode(const K& key, const V& val):left(nullptr),right(nullptr),_key(key),_val(val)
    {}

    V _val;
private:
    BSTreeNode<K,V> *left;
    BSTreeNode<K,V> *right;
    K _key;
};
template<class K, class V>
class BSTree
{
    typedef BSTreeNode<K, V> Node;
public:
    bool Insert(const K& key, const V& value)
    {
        //如果树为空
        if (!_root)
        {
            _root = new Node(key,value);
            return true;
        }
        //如果树不为空,比较大小
        Node *prt = nullptr;
        Node *cur = _root;
        while (cur)
        {
            if (cur->_key < key)
            {
                //右树
                prt = cur;
                cur = cur->right;
            }else if (cur->_key > key)
            {
                //左树
                prt = cur;
                cur = cur->left;
            }else{
                return false;
            }
        }
        cur = new Node(key,value);
        if (prt->_key < cur->_key)
            prt->right = cur;
        else
            prt->left = cur;
        return true;
    }
    Node* Find(const K& key)
    {
        Node *cur = _root;
        while (cur)
        {
            if (cur->_key < key)
                cur = cur->right;
            else if (cur->_key > key)
                cur = cur->left;
            else
                return cur;
        }
        return nullptr;
    }
    bool Erase(const K& key)
    {
        Node *prt = nullptr;
        Node cur = _root;
        while (cur)
        {
            if (cur._key < key)
            {
                prt = cur;
                cur = cur.left;
            }else if (cur._key > key)
            {
                prt = cur;
                cur = cur.right;
            }else{
                //1.左树为空
                //2.右树为空
                //3.左右树都不为空
                if (!cur.left && cur.right)
                {
                    if (!prt)
                        _root = cur.right;
                    else{
                        if (cur == prt->left)
                            prt->left = cur.right;
                        else
                            prt->right = cur.right;
                    }
                    delete cur;
                }else if (cur.left && !cur.right)
                {
                    if (!prt)
                        _root = cur.left;
                    else{
                        if (cur == prt->left)
                            prt->left = cur.left;
                        else
                            prt->right = cur.left;
                    }
                    delete cur;
                } else
                {
                    Node *minNodeP = cur;
                    Node *minNode = cur.right;
                    while (minNode->left)
                    {
                        minNodeP = minNode;
                        minNode = minNode->left;
                    }
                    swap(cur._key,minNode->_key);
                    if (minNodeP->right == minNode)
                        minNodeP = minNode->right;
                    else
                        minNodeP->left = minNode->right;
                    delete minNode;
                }
                return true;
            }
        }
        return false;
    }
    void _InOrder(Node* root)
    {
        if (!root)
            return;
        _InOrder(root->left);
        cout<<root->_key<<" : "<<root->_val<<endl;
        _InOrder(root->right);
    }
    void InOrder()
    {
        _InOrder(_root);
        cout<<endl;
    }
private:
    Node* _root = nullptr;
};

void TestBSTree()
{
    BSTree<string, string> dict;
    dict.Insert("insert", "插入");
    dict.Insert("erase", "删除");
    dict.Insert("left", "左边");
    dict.Insert("string", "字符串");

    string str;
    while (cin>>str)
    {
        auto ret = dict.Find(str);
        if (ret)
        {
            cout << str << ":" << ret->_val << endl;
        }
        else
        {
            cout << "单词拼写错误" << endl;
        }
    }

    string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
    // 统计水果出现的次
    BSTree<string, int> countTree;
    for (auto str : strs)
    {
        auto ret = countTree.Find(str);
        if (ret == nullptr)
        {
            countTree.Insert(str, 1);
        }
        else
        {
            ret->_val++;
        }
    }
    countTree.InOrder();
}

int main()
{
    TestBSTree();
    return 0;
}

*/