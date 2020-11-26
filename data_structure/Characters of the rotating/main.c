//例如：给定s1 =AABCD和s2 = BCDAA，返回1,给定s1=abcd和s2=ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC
#include <stdio.h>
#include <string.h>
void Move(char* src1,int x)
{
    while (x != 0)
    {
        char* str = src1;
        char tmp = *str;
        while (*(str + 1) != '\0')
        {
            *str = *(str + 1);
            str++;
        }
        *str = tmp;
        x--;
    }
}
int judge(char src1[],char src2[])
{
    int i = 0;
    if (strlen(src1) != strlen(src2))
    {
        return 0;
    } else{
        for (i = 0;i <= strlen(src1) - 1;++i)
        {
            Move(src1,1);
            if (strcmp(src1,src2) == 0)
            {
                return 1;
            }
        }
    }
    return 0;

}
int main()
{
    char arr1[] = "AABCD";
    char arr2[] = "ABCDA";

    char arr3[] = "AABCD";
    char arr4[] = "BCDAA";
    int result = judge(arr1,arr2);
    int result1 = judge(arr3,arr4);
    printf("%d\n",result);
    printf("%d\n",result1);
    return 0;
}