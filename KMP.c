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

int KMP(char *haystack, char *needle)
{
    int len_h = strlen(haystack);
    int len_n = strlen(needle);
    if(len_n == 0)
        return 0;

// next数组(前缀表,即不统一减一的实现)
    int next[len_h];
    next[0] = 0;    // next数组首项为0
    int j = 0, i = 1;   // 分别遍历字符串和next数组
    while(i < len_h)
    {
        // 如果不匹配则j退回到上一个字符的next值对应下标的位置
        while(haystack[j] != haystack[i] && j > 0)
        {
            j = next[j-1];
        }
        // 匹配的话就继续遍历
        if(haystack[j] == haystack[i])
            j++;
        next[i] = j;
        i++;
    }

    printf("非减一版本的NEXT[] == [ ");
    for(int k = 0; k < len_h; k++)
        printf("%d ", next[k]);
    printf("]\n");
    // 根据next数组开始遍历源字符串
    i = 0; j = 0;
    while(i < len_h)
    {
        // 匹配失败则回溯指针
        while(j > 0 && haystack[i] != needle[j])
            j = next[j-1];
        // 匹配成功则继续遍历
        if(haystack[i] == needle[j])
            j++;
        // 找到目标字符串,返回下标
        if(j == len_n)
            return (i - len_n + 1);
        i++;
    }
    // 没有找到返回-1
    return -1;
}

int main(int argc, char **argv)
{
    int k = KMP(argv[1], argv[2]);
    printf("匹配的下标为:%d \n", k);
    return 0;
}
