/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *map[10] = 
{
    "0",
    "1",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

char **dfs(char *digits, int* returnSize, char** result, char* pending_ch, int current_len, int total_len)
{
    if (total_len == 0)
        return NULL;
    if (pending_ch == NULL && current_len == 0)
    {
        pending_ch = (char*)malloc((total_len + 1) * sizeof(char));
        pending_ch[total_len] = '\0';
    }
    int num = *digits - '0';
    int loop = 0;
    while(map[num][loop] != '\0')
    {
        pending_ch[current_len] = map[num][loop];
        if (current_len == total_len - 1)
        {
            //result = (char**)realloc(result, (*returnSize+1)*sizeof(char**));
            result[*returnSize] = (char*)malloc(sizeof(char*)*total_len);
            strncpy(result[*returnSize], pending_ch, total_len);
            result[*returnSize][total_len] = '\0';
            *returnSize += 1;
        } 
        else
        {
            result = dfs(digits+1, returnSize, result, pending_ch, current_len+1, total_len);
        }
        loop++;
    }
    return result;
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL)
        return NULL;
    int total_len = 0;
    while(digits[total_len] != '\0')
        total_len++;
    char** result = (char**)malloc(4096*sizeof(char**));
    return dfs(digits, returnSize, result, NULL, 0, total_len);
}


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Please input the cellphone number\n");
        return -1;
    }
    int returnSize = 0;
    char **result = letterCombinations(argv[1], &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", result[i]);
    }
    return 0;
}