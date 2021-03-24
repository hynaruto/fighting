#include <stdio.h>

#define  INT_MAX 2147483647
#define INT_MIN -2147483648
int myAtoi(char * s)
{
    //掠过空格
    while (*s == ' ')
       s++;
    //检查正负号
    int flag = 1;
    if (*s == '-')
    {
        flag = -1;
        s++;
    }else if (*s == '+'){
        s++;
    }
    //开始转为整数,考虑越界
    int result = 0;
    while (*s >= '0' && *s <= '9')
    {
        int num = *s - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && num > 7))
        {
            return flag==1 ? INT_MAX : INT_MIN;
        }else{
            result = result * 10 + num;
            ++s;
        }
    }
    return flag * result;
}

