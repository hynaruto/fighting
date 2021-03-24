//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xn96us/

//有效的字母异位词

//解1:
int Cmp(const void *a,const void *b)
{return *(char*)a - *(char*)b;}

bool isAnagram(char * s, char * t)
{
    //分别给2个字符串排序
    qsort(s,strlen(s),sizeof(char),Cmp);
    qsort(t,strlen(t),sizeof(char),Cmp);

    //判断两个字符串是否相等
    return strcmp(s,t) ? false:true;
}


//解2:
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



