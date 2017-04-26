/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char *str)
{
    char ch;
    long long result = 0;
    int flag = 0;
    int sign = ',';
    while ((ch = *str) != '\0')
    {
        if (ch <= '9' && ch >= '0')
        {
            int i = ch - '0';
            flag = 1;
            result = result * 10 + i;
            if (result > 0x7FFFFFFF)
            {
                if (sign == 1 || sign == ',')
                {
                    result = 0x7FFFFFFF;
                    break;
                }
                else if (sign == -1 && result > 2147483648)
                {
                    result = 2147483648;
                    break;
                }
            }
        }
        else if ((ch == '+' || ch == '-') && flag == 0 && sign == ',')
        {
            sign -= ch;
            flag = 1;
        }
        else if (ch == ' ' && flag == 0)
            ;
        else
        {
            break;
        }
        str++;
    }
    sign = (sign == ',') ? 1 : sign;
    return sign * result;
}

int main()
{
    char str[] = "-2147483648";
    printf("%d\n", myAtoi(str));
    printf("%d\n", atoi(str));
    return 0;
}