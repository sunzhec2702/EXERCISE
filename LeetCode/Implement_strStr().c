/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Subscribe to see which companies asked this question.
*/
#include "utilities.h"

bool cmp(char *haystack, char* needle)
{
    while(*haystack != '\0' && *needle != '\0')
    {
        if(*haystack != *needle)
            return false;
        haystack++;
        needle++;
    }
    if (*needle != '\0')
        return false;
    return true;
}

int strStr(char *haystack, char* needle)
{
    if(needle[0] == '\0'){
        return 0;
    }else if(haystack[0] == '\0'){
        return -1;
    }
    int index = -1;
    while (*haystack != '\0')
    {
        if (cmp(haystack, needle) == true)
        {
            return index + 1;
        }
        index++;
        haystack++;
    }
    return -1;
}

int main()
{
    char haystack[] = "fuck You Dear";
    char needle[] = "Dear";
    printf("%d\n", strStr(haystack, needle));
    return 0;
}