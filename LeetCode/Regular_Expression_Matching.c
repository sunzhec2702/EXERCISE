/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char* s, char* p)
{   
    if (s == NULL || p == NULL) return false;
    if (*p == '\0') return *s == '\0';
    // ".*" matches "", so we can't check (*s == '\0') here.
 
    if (*(p + 1) == '*')
    {
        while ((*s != '\0' && *p == '.') || *s == *p)
        {
            if (isMatch(s + 1, p))
                return true;
            else
                return (isMatch(s, p + 2));
        }
        return isMatch(s, p + 2);
    }
    else if ((*s != '\0' && *p == '.') || *s == *p)
    {
        return isMatch(s + 1, p + 1);
    }
    return false;
}

int main(int argc, char** argv)
{
    char *re = argv[2];
    char *string = argv[1];
    printf("%s %s %s\n", string, isMatch(string, re) == true ? "matches" : "doesn\'t match", re);
    return 0;
}