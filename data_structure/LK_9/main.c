
//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnpvdm/

//外观数列




#include <stdlib.h>
#include <stdio.h>

char * countAndSay(int n)
{
    //递归出口
    if (1==n)
        return "1";
    char *s = countAndSay(n - 1);
    int count = 1,index = 0;
    char *arr = (char*)malloc(sizeof(char) * 4466);
    while (*s != 0)
    {
        if (*s == *(s+1))
            count++;
        else{
            arr[index++] = count + '0';
            arr[index++] = *s;
            count = 1;
        }
        s++;
    }
    arr[index] = 0;
    return arr;
}

int main()
{
    char *s = countAndSay(4);
    printf("%s\n",s);
    return 0;
}