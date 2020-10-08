#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1,const char* str2)
{
    assert(str1 && str2);
    while (*str1 == *str2)
    {
        if (*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    if (*str1 > *str2)
        return 1;
    else
        return -1;
}
int main()
{
    char * p1 = "abcdef";
    char * p2 = "abcdqw";
    int ret = my_strcmp(p1,p2);
    printf("ret = %d\n",ret);
    return 0;
}