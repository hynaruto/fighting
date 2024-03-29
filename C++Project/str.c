//
// Created by 胡杨 on 2021/9/26.
//
#include "str.h"
void str_trim_crlf(char *str)
{
    char *p = str + (strlen(str) - 1);
    while (*p == '\r' || *p == '\n')
        *p-- = '\0';
}
void str_split(const char *str,char *left,char *right,char token)
{
    char *pos = strchr(str,token);
    if (pos == NULL)
        strcpy(left,str);
    else
    {
        strncpy(left,str,pos - str);
        strcpy(right,pos + 1);
    }
}

void str_upper(char *str)
{
    while (*str != '\0')
    {
        if (*str >= 'a' && *str <= 'z')
            *str -= 32;
        str++;
    }
}