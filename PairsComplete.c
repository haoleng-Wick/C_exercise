/*
 *
 * 输入一个只包括括号字符的字符串s;
 * 判断其括号是否匹配
 * 1 <= s.length <= 10000
 *
 * 使用栈来进行匹配
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char stack[5000];
int stack_top = 0;

void push(char c)
{
    stack_top++;
    stack[stack_top] = c;
}

char pop()
{
    char c;
    c = stack[stack_top];
    stack_top--;
    return c;
}

bool is_stack_empty()
{
    return stack_top == 0;
}

bool isValid(char *s)
{
    long lens = strlen(s);

    for(int i = 0; i < lens; i++)
    {
        switch(s[i])
        {
            case '(': 
            case '[': 
            case '{': 
                push(s[i]);break;
            case ')':
                if('(' != pop())
                    return false; break;
            case ']':
                if('[' != pop())
                    return false; break;
            case '}':
                if('{' != pop())
                    return false; break;
        }
    }
    return is_stack_empty()? true : false;
}

int main(int argc, char **argv)
{
    bool flag = true;
    char s[10000];
    stack_top = 0;
    printf("please input the string:\n ");
    scanf("%s", s);

    printf("your input array is: '%s'\n", s);
    for(int i =0; i < strlen(s); i++)
    {
        if(s[i] != '(' && s[i] != ')' &&
           s[i] != '[' && s[i] != ']' &&  
           s[i] != '{' && s[i] != '}') 
            flag = false;
    }
    if(!flag)
        printf("ERROR: your input is illegal!\n");

    else
    {
        bool is_valid = isValid(s);
        if(is_valid)
            printf("the string is valid.\n");
        else
            printf("the string is'n valid.\n");
    }

    return 0;
}
