//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn5z8r/

//字符串中的第一个唯一字符

#include <stdio.h>
#include <string.h>
#include <assert.h>

int firstUniqChar(char *s)
{
    assert(s);
    int i;
    int arr[26] = {0};
    //第一个循环统计字符串中每个字母出现的次数.
    for (i = 0;i < strlen(s);++i)
    {
        arr[s[i] - 'a']++;
    }
    //第二个循环判断每个字母出现的次数是不是为1，如果是返回下标。
    for(i = 0;i < strlen(s);++i)
    {
        if (arr[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}
int main()
{
    char *s = "leetcode";
    int result= firstUniqChar(s);
    printf("%d\n",result);
}