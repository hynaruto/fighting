//模仿qsort的功能实现一个通用的冒泡排序
#include <stdio.h>
#include <string.h>
#include <assert.h>
void swap(char *p, char *q, size_t num)
{
    while (num){
        char temp = *p;
        *p = *q;
        *q = temp;
        num--;
        p++, q++;
    }
}

void* my_qsort(void* base,size_t num,size_t size,int (*comp)(const void*,const void*))
{
    assert(base);
    assert(comp);
    int flag = 0;
    char* p = (char*)base;
    for (int i = 0; i < num - 1;++i)
    {
        for (int j = 0;j < num - 1 - i;++j)
        {
            if (comp(p + j*size, p + (j + 1)*size) > 0)
            {
                swap(p + j*size, p + (j + 1)*size, size);
                flag = 1;
            }
        }
        if (flag ==0)
        {
            break;
        }
    }

}

int main()
{
    char arr[] = {"a2bcd","a4bcd","abcd","a7bcd"};
    int num = sizeof(arr) / sizeof(arr[0]);
    my_qsort(arr, num, sizeof(int), swap);
}
