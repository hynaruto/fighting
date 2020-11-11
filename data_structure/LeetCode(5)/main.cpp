//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出: true
//示例 2:
//输入: s = "rat", t = "car"
//输出: false
#include <string.h>
bool isAnagram(char * s, char * t)
{
    if (strlen(s) != strlen(t))
    {
        return false;
    }
    int arr[26] = {0};
    for (int i = 0;i < strlen(s);++i)
    {
        arr[s[i] - 'a']++;
        arr[t[i] - 'a']--;
    }
    for (int i = 0;i < 26;++i)
    {
        if (arr[i] != 0)
        {
            return false;
        }
    }
    return true;
}