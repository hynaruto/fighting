#include <iostream>
using namespace std;
namespace hy
{
    class string
    {
        friend ostream& operator<<(ostream& _cout, const hy::string& s);
    public:
        typedef char* iterator;
        static size_t npos;
    public:
        //构造函数
        string():_str(nullptr),_size(0),_capacity(0)
        {}
        string(const char* str)
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str,str);
        }
        //拷贝构造
        string(const string& s):_str(nullptr),_size(0),_capacity(0)
        {
            string tmp(s._str);
            this->swap(tmp);
        }
        //赋值
        string& operator=(const string &s)
        {
            if (this != &s)
            {
                string tmp(s._str);
                this->swap(tmp);
            }
            return *this;
        }
        //析构函数
        ~string()
        {
            delete []_str;
            _str = nullptr;//预防野指针
        }

        //////////////////////////////////////////////////////////////
        // iterator
        iterator begin()
        {return _str;}
        iterator end()
        {return _str + _size;}
        /////////////////////////////////////////////////////////////
        // modify
        void push_back(char c)
        {
            //插入之前判断容量是否足够
            if (_size + 1 > _capacity)
            {
                _capacity == 0 ? 1 : (2 * _capacity);
                reserve(_capacity);
            }
            _str[_size++] = c;
            _str[_size] = '\0';
        }
        string& operator+=(char c)
        {
            //直接调用push_back
            push_back(c);
            return *this;
        }
        void append(const char* str)
        {
            size_t size = strlen(str);
            if (_size + size > _capacity)
                reserve(_size + size);
            strcat(_str,str);
            _size += size;
        }
        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }
        void clear()
        {
            _size = 0;
            _str[_size] = '\0';
        }
        void swap(string& s)
        {
            std::swap(_str,s._str);
            std::swap(_size,s._size);
            std::swap(_capacity,s._capacity);
        }
        const char* c_str()const
        {return _str;}
        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const
        {return _size;}
        size_t capacity()const
        {return _capacity;}
        bool empty()const
        {return _size==0;}
        void resize(size_t n, char c = '\0')
        {
            if (n > _size)
            {
                if (n > _capacity)
                {
                    reserve(n);
                    memset(_str+_size,c,n - _size);
                }
                _size = n;
                _str[_size] = '\0';
            }
        }
        void reserve(size_t n)
        {
            //如果新的容量大于旧的容量，则开辟空间，将原有数据拷贝至新空间
            if (n > _capacity)
            {
                char *str = new char[n + 1];//+1自己预留出\0;
                strcpy(str,_str);
                delete [] _str;
                //更改指向
                _str = str;
                _capacity = n;
            }
        }
        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index)
        {
            assert(index < _size);
            return _str[index];
        }
        const char& operator[](size_t index)const
        {
            assert(index < _size);
            return _str[index];
        }
        /////////////////////////////////////////////////////////////
        //relational operators
        bool operator<(const string& s)
        {
            int res = strcmp(_str,s._str);
            return res < 0;
        }
        bool operator<=(const string& s)
        {return !(*this > s);}
        bool operator>(const string& s)
        {
            int res = strcmp(_str,s._str);
            return res > 0;
        }
        bool operator>=(const string& s)
        {return !(*this < s);}
        bool operator==(const string& s)
        {return strcmp(_str,s._str);}
        bool operator!=(const string& s)
        {return !strcmp(_str,s._str);}
        // 返回c在string中第一次出现的位置
        size_t find (char c, size_t pos = 0) const
        {
            //assert(pos < _size);
            int new_pos = (pos == npos ? _size - 1:pos);
            for (int i = new_pos;i < _size;++i)
            {
                if (_str[i] == c)
                    return i;
            }
            return npos;
        }
        // 返回子串s在string中第一次出现的位置
        size_t find (const char* s, size_t pos = 0) const
        {
            int i = pos,j = 0;
            while (i < _size && j < strlen(s))
            {
                if (_str[i] == s[j])
                    ++i,++j;
                else{
                    j = 0,i = i - j + 1;
                }
            }
            if (j > strlen(s))
                return i - strlen(s);
            return npos;
        }
        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c)
        {
            if (_size + 1 > _capacity)
                reserve(_capacity * 2);
            for (int i = _size;i > pos;--i)
                _str[i] = _str[i - 1];
            _str[pos] = c;
            _size++;
            return *this;
        }
        string& insert(size_t pos, const char* str)
        {
            int len = strlen(str);
            if (_size + len > _capacity)
                reserve(_capacity * 2);
            for (int i = _size;i >= pos;--i)
                _str[i + len] = _str[i];
            int k = 0;
            for (int i = pos;k < len;++i,++k)
                _str[i] = _str[k];
            _size += len;
            return *this;
        }

        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len)
        {
            if (pos + len <= _size)
            {
                assert(pos + len <= _size);
                char *tmp = new char[_size-len+1];
                memset(tmp, 0, _size-len+1);
                strncpy(tmp, _str, pos);
                strncat(tmp, _str+pos+len, _size-pos-len+1);

                strcpy(_str, tmp);
                _size -= len;
                delete []tmp;
            }else{
                //用\0做覆盖
                _str[pos] = _str[_size];
                _size = strlen(_str);
            }
            return *this;
        }
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
    };
    ostream& operator<<(ostream& _cout, const hy::string& s)
    {_cout<<s._str;}
}

int main()
{
    hy::string s1 = "hello";
    s1.erase(3,5);
    for (auto &e : s1)
        cout<<e;
    cout<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.capacity()<<endl;
    /*
    hy::string str("hello c++");
    str.push_back('+');
    for (auto &e : str)
        cout<<e;
    cout<<endl;

    hy::string str2(str);
    for (auto &e : str2)
        cout<<e;
    cout<<endl;

    hy::string str3;
    str3 = str2;
    for (auto &e : str3)
        cout<<e;
    cout<<endl;

    hy::string str4 = str;
    for (auto &e : str3)
        cout<<e;
    cout<<endl;
    cout<<str4.size()<<endl;
    cout<<str4.capacity()<<endl;
    str4.resize(20);
    cout<<str4.size()<<endl;
    cout<<str4.capacity()<<endl;
    str4.erase(1,1);
    for (auto &e : str4)
        cout<<e;
    cout<<endl;
    cout<<str4.size()<<endl;
    cout<<str4.capacity()<<endl;
    */
}