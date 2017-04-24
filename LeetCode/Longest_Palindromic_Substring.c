/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
Subscribe to see which companies asked this question.

Show Tags
Show Similar Problems
*/

#include <stdio.h>
#include <stdlib.h>

int searchBidirect(char *s, int i, int j)
{
    while (i >= 0 && s[j] != '\0' && s[i] == s[j])
    {
        i--;
        j++;
    }
    return j-i-1;
}

char *longestPalindrome(char *s)
{
    char *current = s;
    int max_len = 0;
    int start = 0, end = 0;
    int index = 0;
    if (s == NULL)
        return NULL;
    while (s[index] != '\0')
    {
        int len1 = searchBidirect(s, index, index);
        int len2 = searchBidirect(s, index, index + 1);
        int len = (len1 > len2) ? len1 : len2;
        if (max_len < len)
        {
            start = index - (len - 1) / 2;
            end = index + (len / 2);
            printf("index %d, len %d start %d end %d\n", index, len, start, end);
            max_len = len;
        }
        index++;
    }
    printf("max_Len is %d, start %d, end %d\n", max_len, start , end);
    s[start + max_len] = '\0';
    return &s[start];
}

int main()
{
    char string[] = "cbbd";
    char *result = longestPalindrome(string);
    printf("result : %s\n", result);
    return 0;
}