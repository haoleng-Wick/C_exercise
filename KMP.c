/*
 * 给定两个字符串haystack和needle
 * 在haystack中找出needle字符串的第一个匹配项的下标并返回
 * 如果needle不是haystack的子集，返回-1
 * input : haystack = "abcabcbb"; needle = "cab"
 * output: 2 
 *
 * 用到KMP字符串匹配算法
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int KMP(char *haystack, char *needle)
{
    if(strlen(needle) == 0)
        return 0;
    // next[]
    int *next = (int *)malloc(strlen(needle) * sizeof(int));
    int j = -1;
    next[0] = j;
    printf("next[] = [ %d ",next[0]);
    for(int i = 1; i < strlen(needle); i++) // 从下标为一开始遍历
    {
        while(j >= 0 && needle[i] != needle[j+1])	// 前后缀不相同
            j = next[j];	// 向前回溯
        if(needle[i] == needle[j+1])	// 前后缀相同
            j++;
        next[i] = j;	// 将j(前缀的长度)赋值给next[i]
        printf("%d ",next[i]);
    }
    printf("]\n");

    // KMP
    j = -1;
    for(int i = 0; i < strlen(haystack); i++)
    {
        while(j >= 0 && haystack[i] != needle[j+1]) // 回溯
            j = next[j];
        if(haystack[i] == needle[j+1])  // 向前遍历
            j++;
        if(j == strlen(needle) - 1) // 判断是否匹配完成
        {
            free(next);
            next = NULL;
            return(i - strlen(needle) + 1); // 返回haystack的下标
        }
    }
    free(next);
    next = NULL;
    return -1;
}

int main(int argc, char **argv)
{
    if(argc != 3)
        fprintf(stderr, "Usage: ./a.out abcabcbb cab\n");

    int k = KMP(argv[1], argv[2]);
    printf("The index is: %d \n", k);
    return 0;
}
