#include <iostream>
#include <vector>
using namespace std;
namespace hy
{
    template <class _Ty>
    class vector
    {
    public:
        typedef _Ty* iterator;
        typedef const _Ty* const_iterator;
    public:
        vector():_First(nullptr),_Last(nullptr),_End(nullptr)
        {}
        //拷贝构造
        vector(const vector<_Ty> &v):_First(nullptr),_Last(nullptr),_End(nullptr)
        {
            reserve(v.capacity());
            auto it = begin();
            auto is = (iterator) v.cbegin();
            while (is != v.cend())
                *it++ = *is++;
            //重定向
            _Last = _First + v.Size();
            _End = _First + v.capacity();
        }
        ~vector()
        {
            delete  _First;
            _First = _Last = _End = nullptr;
        }
        /*
        template <class Inputlterator>
        vector(Inputlterator first, Inputlterator last)
        {
            //预留空间
            reserve(last - first);
            while(first != last)
            {
                push_back(*first);
                ++first;
            }
        }
         */
    public:
        _Ty&operator[](size_t pos)
        {return _First[pos];}
        const _Ty&operator[](size_t pos)const
        {return _First[pos];}
        vector<_Ty>&operator=(vector<_Ty> v)
        {
            swap(v);
            return *this;
        }
    public:
        void push_back(const _Ty &x)
        {insert(end(),x);}
        void pop_back()
        {erase(--end());}
        void swap(vector<_Ty> &v)
        {
            ::swap(_First,v._First);
            ::swap(_Last,v._Last);
            ::swap(_End,v._End);
        }
        iterator insert(iterator _Ptr,const _Ty &x)
        {
            //确定空间是否足够
            if (_Last == _End)
            {
                //定位
                size_t _Ptr_size = _Ptr - _First;
                size_t new_size = Size()==0 ? 1 : Size() * 2;
                reserve(new_size);
                _Ptr = _First +_Ptr_size;
            }
            //中间插入情况
            iterator end = _Last;
            while (end > _Ptr)
            {
                *end = *(end - 1);
                --end;
            }
            //插入元素
            *_Ptr = x;
            ++_Last;
            return _Ptr;
        }
        //删除数据
        iterator erase(iterator pos)
        {
            iterator begin = pos + 1;
            while (begin != _Last)
            {
                *(begin - 1) = *begin;
                ++begin;
            }
            //size--
            --_Last;
            return pos;
        }
    public:
        size_t Size()const
        {return _Last - _First;}
        size_t capacity()const
        {return _End - _First;}
        iterator begin()
        {return _First;}
        const_iterator cbegin()const
        {return _First;}
        const_iterator cend()const
        {return _Last;}
        iterator end()
        {return _Last;}
    public:
        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t old_size = Size();
                //申请新的空间大小
                _Ty *new_first = new _Ty[n];
                //将原来的数据拷贝到新的空间
                memcpy(new_first,_First,sizeof(_Ty) * old_size);
                //删除原来的空间
                delete[]_First;
                //重新更改指向
                _First = new_first;
                _Last = _First + old_size;
                _End = _First + n;
            }
        }
        void resize(size_t n,const _Ty &x=_Ty())
        {
            //缩小
            if (n <= Size())
            {
                _Last = _First + n;
                return;
            }
            //扩大
            //判断空间够不够
            if (n > capacity())
                 reserve(n);
            iterator cur = _Last;
            _Last = _First + n;
            while (cur != _Last)
            {
                *cur = x;
                ++cur;
            }
        }
    private:
        iterator _First;
        iterator _Last;
        iterator _End;
    };
}
int main()
{
    hy::vector<int> v;
    hy::vector<int> v1;
    /*
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    hy::vector<int> v2(arr,arr + size);
     */
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout<<"size:"<<v.Size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    v.push_back(5);
    cout<<"size:"<<v.Size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    for (auto &e : v)
        cout<<e<<" ";
    cout<<endl;
    v.reserve(50);
    cout<<"size:"<<v.Size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;

    v.resize(2);
    for (auto &e : v)
        cout<<e<<" ";
    cout<<endl;
    cout<<"size:"<<v.Size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    v.resize(5,8);
    for (auto &e : v)
        cout<<e<<" ";
    cout<<endl;
    cout<<"size:"<<v.Size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    v1 = v;
    for (auto &e : v)
        cout<<e<<" ";
    cout<<endl;
    auto pos = find(v.begin(),v.end(),2);
    v1.erase(pos);
    for (auto &e : v)
        cout<<e<<" ";
    cout<<endl;
    cout<<"size:"<<v.Size()<<endl;
    cout<<"capacity:"<<v.capacity()<<endl;
    return 0;
}