#include <stdio.h>
#include <assert.h>
void* my_memmove(void* dest, const void* src,size_t count)
{
    assert (dest != NULL);
    assert (src != NULL);
    void* ret =  dest;
    if (dest < src){
        // 从前向后拷贝
        while (count--)
        {
            *(char*)dest == *(char*)src;
            ++(char*)dest;
            ++(char*)src;
        }
    } else{
        //从后向前
        while (count--)
        {
            *((char*)dest + count) = *((char*)src + count);
        }
    }
    return ret;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    my_memmove(arr,arr+2,20);
    return 0;
}