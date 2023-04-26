/*
 * 给定一个字符串s，找出其中不含重复字符的最长子串的长度
 * input : "abcabcbb", "haolenghello", "aaa"
 * output: 3, 7, 1
 *
 * 用到滑动窗口和标记数组
 */
#include <stdio.h>
#include <stdbool.h>

unsigned char lenght_unique_string(char *s)
{
    unsigned char max = 0;
    bool hash[128] = {false};    // 存放字符先后出现的顺序
    unsigned char left = 0, right = 0;// 双指针实现滑动窗口

    while(s[right]) // 遍历字符串
    {
        if(hash[s[right]])  // 如果哈希表中记录了该字符
        {
            hash[s[left]] = false;    // 从左边缩小窗口直至没有相同的字符为止
            left++;
        }
        else    // 如果哈希表中没有记录过该字符
        {
            hash[s[right]] = true;   // 记录该字符 窗口大小+1
            right++;
        }
        max = max < (right - left) ? (right - left) : max;
    }
    for(int i = left; i < right; i++)
        printf("%c", s[i]);
    printf("\n");
    return max;
}

int main(int argc, char **argv)
{
    unsigned char len = lenght_unique_string(argv[1]);
    printf("The longest unique string's lenght is %d\n", len);
    return 0;
}
