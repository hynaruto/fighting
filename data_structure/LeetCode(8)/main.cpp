//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
// 例如输入字符串"I am a student. "，则输出"student. a am I"。
#include <cstring>
#include <cstdlib>
char* reverseWords(char* s){
    int len = strlen(s);
    char *res = (char *)malloc(sizeof(char) * (len+1));
    int i, count = 0, j = 0, flag = 0;
    for(i = len - 1;i >= 0;i--)
    {
        if(s[i] != ' ')
        {
            count++;
        }
        else if(s[i] == ' '&&count !=0)
        {
            if(i != 0&&flag != 0)
            {
                res[j++] = ' ';
            }
            int x = count;
            while(count)
            {
                res[j++] = s[i + x - count + 1];
                count--;
            }
            flag = 1;
            count = 0;
        }
    }
    if(count != 0)
    {
        if(flag == 1)
        {
            res[j++] = ' ';
        }
        int x = count;
        while(count)
        {
            res[j++] = s[i + x - count + 1];
            count--;
        }
    }

    res[j] = '\0';
    return res;
}
