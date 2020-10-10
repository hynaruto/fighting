#include <stdio.h>
#include <assert.h>

void * my_memcpy(void* dest,const void* src,size_t num)
{
    assert(dest != NULL);
    assert(src != NULL);
    void* ret = dest;
    while (num--)
    {
        *(char*)dest = *(char*)src;
        ++(char*)dest;
        ++(char*)src;


    }
    return ret;
}

int main()
{
    int arr1[] = {1,2,3,4,5};
    int arr2[5] = {};
    my_memcpy(arr2,arr1, sizeof(arr1));
    return 0;
}