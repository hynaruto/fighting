#include <stdio.h>
#include <string.h>
char* my_strncpy(char* str1, const char* str2,size_t count)
{
    char *start = str1;
    while (count && (*str1++ = *str2++))
    {
        count--;
    }
    if (count)
    {
        while (--count)
            *str1++ = '\0';
    }
    return start;
}
int main()
{
    char p1[10] = "abcdefg";
    char p2[] = "hello";
    char *ret = my_strncpy(p1,p2,3);
    printf("%s\n",ret);
    return 0;
}