/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
char* convert(char* s, int numRows)
{
    int str_len = strlen(s);
    char *result = (char*)malloc(str_len + 1);
    result[str_len] = '\0';
    int current_index = 0;
    int step = (numRows == 1) ? 1 : 2 * numRows - 2;
    for (int i = 0; i < numRows; i++)
    {
        int j = 0, index = 0;
        while((j*step + i) < str_len && current_index < str_len)
        {
            index = j * step + i;
            result[current_index++] = s[index];
            if ((i != 0) && (i != (numRows - 1)))
            {
                if ((index + step - 2 * i) < str_len)
                    result[current_index++] = s[index + step - 2 * i];
            }
            j++;
        }
    }
    return result;
}

int main()
{
    char str[] = "PAYPALISHIRING";
    printf("%s\n", convert(str, 3));
    return 0;
}