/*
 * 判断字符串中是否含有相同的字符，如果有则返回false,没有则返回true
 * input : "acdefghxya", "abcdefgh"
 * output: false, true
 *
 * 用到位运算
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* 使用标记数组实现
bool is_unique(char *astr)
{
    bool arr[26] = {0};
    for(char *cur = astr; *cur != '\0'; cur++)
    {
        unsigned char temp = *cur - 'a';
        if(arr[temp])
            return false;
        arr[temp] = true;
    }
    return true;
}
*/

/* 使用位运算实现 
 * 使用int型变量表示26位arr[]
 * 通过其值是否为1来判断
 * 原理与第一种方法类似
 */
bool is_unique(char *astr)
{
    int table = 0;
    for(char *cur = astr; *cur != '\0'; cur++)
    {
        unsigned char temp = *cur - 'a';
        if(table & (0x01 << temp))
            return false;
        else
            table = table | (0x01 << temp);
    }
    return true;
}

int main(int argc, char **argv)
{
    bool flag = is_unique(argv[1]);
    if(flag)
        printf("True\tthe string has unique character.\n");
    else
        printf("False\thas no unique character.\n");
    return 0;
}
