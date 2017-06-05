/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Subscribe to see which companies asked this question.
*/

#include "utilities.h"
/*
看了參考，別人給出了一個更好的方案。就是從前往後掃描，去掉所有的invalid。其实就是没有"("的")",在从后往前扫描，去掉没有")"的"("，用##代替
然后在从前往后扫一次，找到最长的就行了。

((()))))((
从前往后 ((()))##((
从后往前 ((()))####
最长就是6.
所以这道题告诉我们预处理也很重要。如果扫一遍可以预处理掉很多问题，那就果断的先扫一遍。
*/

int longestValidParentheses(char *s)
{
    if (s == NULL)
        return 0;
    // scan from front.
    char *index = s;
    int stack = 0;
    while (*index != '\0')
    {
        if (*index == '(')
        {
            stack++;
            index++;
        }
        else if (*index == ')' && stack > 0)
        {
            stack--;
            index++;
        }
        else if (*index == ')' && stack <= 0)
        {
            stack = 0;
            *index = '#';
            index++;
        }
        else
        {
            index++;
        }
    }
    printf("%s\n", s);
    stack = 0;
    while (index >= s)
    {
        if (*index == ')')
        {
            stack++;
            index--;
        }
        else if (*index == '(' && stack > 0)
        {
            stack--;
            index--;
        }
        else if (*index == '(' && stack <= 0)
        {

            stack = 0;
            *index = '#';
            index--;
        }
        else
        {
            index--;
        }
    }
    printf("%s\n", s);
    //scan to get the max.
    int max_len = 0, len = 0;
    index = s;
    while (*index != '\0')
    {
        if (*index != '#')
        {
            len++;
        }
        else
        {
            max_len = (max_len < len) ? len : max_len;
            len = 0;
        }
        index++;
    }
    max_len = (max_len < len) ? len : max_len;
    return max_len;
}

int main()
{
    char input[] = "()";
    printf("longest valid parentheses %d\n", longestValidParentheses(input));
    return 0;
}