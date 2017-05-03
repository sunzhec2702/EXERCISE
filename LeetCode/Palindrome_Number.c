/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    int t, result = 0;
    t = x;
    while (t > 0)
    {
        int i = t - t / 10 * 10;
        result = result * 10 + i;
        t = t / 10;
    }
    if (result == x)
        return true;
    else
        return false;
}

int main(int argc, char **argv)
{
    int number = atoi(argv[1]);
    printf("%d is %s\n", number, isPalindrome(number) == true ? "TRUE" : "FALSE");
    return 0;
}