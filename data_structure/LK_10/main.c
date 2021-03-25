

//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnmav1/


char * longestCommonPrefix(char ** strs, int strsSize)
{
    char *arr = malloc(sizeof(char*) * 200);
    if (strsSize == 1)
        return strs[0];
    if (strsSize == 0)
        return "";
    //让arr和strs[0]、strs[1]的前缀相同
    for (int i = 0;;++i)
    {
        if (strs[0][i] == '\0' || strs[1][i] == '\0')
        {
            arr[i] = '\0';
            break;
        }
        if (strs[0][i] == strs[1][i])
        {
            arr[i] = strs[0][i];
            arr[i + 1] = '\0';
        }else{
            arr[i] = '\0';
            break;
        }
    }

    //以arr为基准和第三个进行比较
    for (int i = 2;i < strsSize;++i)
    {
        if (arr[0] == '\0' || strs[i][0] == '\0')
            return "";
        for (int j = 0;strs[i][j] != '\0' || arr[j] != '\0';++j)
        {
            if (strs[i][j] != arr[j])
            {
                arr[j] = '\0';
                break;
            }
        }
    }
    return arr;
}