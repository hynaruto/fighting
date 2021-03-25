
//https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/xnr003/

//实现 strStr() 函数。
//
//给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
//


 int strStr(char * haystack, char * needle)
{
    int len_1 = strlen(haystack),len_2 = strlen(needle);
    int index = 0;//用来记录字符出现的第一个位置
    if (len_2 == 0)
        return 0;
    if (len_2 < len_2)
        return -1;
    //开始遍历haystack数组，找到needle第一个字符开始的位置，并且判断len_1 - i >= len_2
    for (int i = 0;i < len_1;++i)
    {
        if (haystack[i] == needle[0] && (len_1 - i >= len_2))
        {
            int count = 0;
            index = i;
            //用指针记录haystack当前位置
            int ptr = i;
            //遍历needle数组
            for (int j = 0;j < len_2;++j)
            {
                if (needle[j] == haystack[ptr])
                {
                    count++;
                    ptr++;
                }
            }
            if (count == len_2)
                return index;
        }
    }
    return -1;
}