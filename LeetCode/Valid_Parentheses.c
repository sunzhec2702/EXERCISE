/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX (4096000)

bool isValid(char* s) {
    char stack[MAX];
    int index = 0;
    while (*s != '\0')
    {
        char ch = *s;
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[index] = ch;
            index++;
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (index == 0)
                return false;
            char ex;
            switch (ch)
            {
                case ')':
                ex = '(';
                break;
                case '}':
                ex = '{';
                break;
                case ']':
                ex = '[';
                break;
            }
            if (stack[index - 1] != ex)
            {
                return false;
            }
            else
            {
                stack[index - 1] = '\0';
                index--;
            }
        }
        else
            return false;
        s++;
    }
    if (index != 0)
        return false;
    return true;
}

int main(int argc, char **argv)
{
    printf("%s : %s\n", argv[1], isValid(argv[1]) == true ? "VALID" : "INVALID");
    return 0;
}