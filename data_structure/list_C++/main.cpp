#include <iostream>
#include <list>
using namespace std;
namespace hy
{
    template <class _Ty>
    class my_iterator;
    template <class _Ty>
    class list;
    template <class _Ty>
    class Node
    {
        friend class list<_Ty>;
        friend class my_iterator<_Ty>;
    public:
        //初始化
        Node():_val( _Ty()),_next(nullptr),_prev(nullptr)
        {}
        Node(const _Ty &val,Node *next = nullptr,Node *prev = nullptr):_val(val),_next(next),_prev(prev)
        {}
        ~Node() = default;
    private:
        Node *_next;
        Node *_prev;
        _Ty _val;
    };
    template <class _Ty>
    class my_iterator
    {
        typedef my_iterator<_Ty> self;
    public:
        explicit my_iterator(Node<_Ty> *_P):_Ptr(_P)
        {}
    public:
        _Ty&operator*()
        {return _Ptr->_val;}
        bool operator!=(const self &it)
        {return (_Ptr != it._Ptr);}
        Node<_Ty> *myNode()
        {return _Ptr;}
        self&operator++()
        {
            _Ptr = _Ptr->_next;
            return *this;
        }
        self operator++(int)
        {
            self tmp(*this);
            ++*this;
            return tmp;
        }
        self operator--()
        {
            _Ptr = _Ptr->_prev;
            return *this;
        }
    private:
        Node<_Ty> *_Ptr;
    };
    template <class _Ty>
    class list
    {
    public:
        typedef  my_iterator<_Ty> iterator;
        typedef iterator _It;
    public:
        iterator begin()
        {return iterator(_Head->_next);}
        iterator end()
        {return iterator(_Head);}
    public:
        void Push_back(const _Ty &x)
        {insert(end(),x);}
        void Push_front(const _Ty &x)
        {insert(begin(),x);}
    public:
        size_t size()const
        {return _Size;}
        bool empty() const
        {return size()==0;}
    public:
        _Ty& front()
        {return *begin();}
        const _Ty& front()const
        {return *begin();}
        _Ty back()
        {return *--end();}
        const _Ty& back()const
        {return *--end();}
    public:
        iterator insert(iterator _P,const _Ty &x)
        {
            auto *_S = new Node<_Ty>(x);
            Node<_Ty> *cur = _P.myNode();
            _S->_next = cur;
            _S->_prev = cur->_prev;
            _S->_next->_prev = _S;
            _S->_prev->_next = _S;
            _Size++;
            return iterator(_S);
        }
    public:
        list():_Size(0)
        {
            CreatHead();
        }
        list (int n,const _Ty& value = _Ty())
        {
            CreatHead();
            while (--n)
            {
                insert(begin(),value);
            }
        }
        list (_It _first,_It _last)
        {
            CreatHead();
            while (_first != _last)
            {
                Push_back(*_first);
                ++_first;
            }
        }
        list(list &lt)
        {
            CreatHead();
            list tmp(lt.begin(),lt.end());
            swap(_Head,tmp._Head);
            _Size = lt.size();
        }
        list<_Ty>&operator=(list<_Ty> &lt)
        {
            if (this != &lt)
                this->swap(lt);
            return *this;
        }
        ~list()
        {
            clear();
            delete _Head;
            _Head = nullptr;
        }

    public:
        void swap(list<_Ty> &lt)
        {
            Node<_Ty> tmp = _Head;
            _Head = lt._Head;
            lt._Head = tmp;
        }
    public:
          void clear()
          {
            erase(begin(),end());
          }
    protected:
        void CreatHead()
        {
            _Head = new Node<_Ty>;
            _Head->_next = _Head;
            _Head->_prev = _Head;
        }
    public:
        iterator erase(iterator _P)
        {
            Node<_Ty> *cur = _P.myNode();
            Node<_Ty> *next_node = cur->_next;
            cur->_next->_prev = cur->_prev;
            cur->_prev->_next = cur->_next;
            delete(cur);
            --_Size;
            return  iterator(next_node);
        }
        iterator erase(iterator _first,iterator _last)
        {
            while (_first != _last)
            {
                _first = erase(_first);
            }
            return iterator(_last);
        }
    private:
        Node<_Ty> *_Head;
        size_t _Size;
    };
}
int main()
{
    hy ::list<int> mylist(10,2);
    mylist.Push_back(1);
    mylist.Push_back(2);
    mylist.Push_back(3);
    hy::list<int> :: iterator it = mylist.begin();
    while (it != mylist.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    mylist.erase(mylist.begin());
    it = mylist.begin();
    while (it != mylist.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    mylist.clear();
    it = mylist.begin();
    while (it != mylist.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    return 0;
}