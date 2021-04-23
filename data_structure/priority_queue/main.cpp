#include <iostream>

namespace hy
{
    template<class T>
    struct less
    {
        bool operator()(const T& left, const T& right)
        {
            return left < right;
        }
    };
    template<class T>
    struct greater
    {
        bool operator()(const T& left, const T& right)
        {
            return left > right;
        }
    };


    namespace hy
    {
        //函数对象 less
        template<class T>
        struct less
        {
            bool operator()(const T& left, const T& right)
            {
                return left < right;
            }
        };
        template<class T>
        struct greater
        {
            bool operator()(const T& left, const T& right)
            {
                return left > right;
            }
        };

        template <class T, class Container = std::vector<T>, class Compare = less<T> >
        class priority_queue
        {
        public:
            priority_queue():c()
            {}
            template <class InputIterator>
            priority_queue(InputIterator first, InputIterator last)
                    :c(first, last)
            {
                int count = c.size();
                int root = ((count - 2) >> 1);
                for (; root >= 0; root--)
                    AdjustDown(root);
            }
            bool empty() const
            {
                return c.empty();
            }
            size_t size() const
            {
                return c.size();
            }
            const T& top() const
            {
                return c.front();
            }
            void push(const T& x)
            {
                c.push_back(x);
                //push_heap(c.begin(), c.end(), comp);
                AdjustUp(c.size() - 1);
            }
            void pop()
            {
                if (empty())
                    return;
                std:swap(c.front(), c.back());
                c.pop_back();
                AdjustDown(0);
            }
        private:
            void AdjustUp(int child)
            {
                int parent = ((child - 1) >> 1);
                while (child)
                {
                    if (Com(c[parent], c[child]))
                    {
                        std::swap(c[child], c[parent]);
                        child = parent;
                        parent = ((child - 1) >> 1);
                    }
                    else
                        return;

                }
            }
            void AdjustDown(int parent)
            {
                int child = parent * 2 + 1;
                while (child < c.size())
                {
                    if (child + 1 < c.size() && Com(c[child], c[child+1]))
                        child += 1;
                    if (Com(c[parent], c[child]))
                    {
                        std::swap(c[child], c[parent]);
                        parent = child;
                        child = parent * 2 + 1;
                    }
                    else
                        return;
                }
            }
        private:
            Container c;
            Compare Com;
        };
    };