//给你一个字符串 s 和一个 长度相同 的整数数组 indices 。请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。返回重新排列后的字符串。
#include <cstdlib>
char * restoreString(char * s, int* indices, int indicesSize){
    char *tmp=(char *)calloc(sizeof(char),indicesSize+1);
    for(int i=0;i<indicesSize;i++){
        tmp[indices[i]]=s[i];
    }
    return tmp;
}