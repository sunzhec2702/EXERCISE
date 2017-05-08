/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **dfs(int l, int r, char**result, int*returnSize, char*tmp_str,int tmp_index)
{
    if (l == 0 && r == 0)
    {
        result[*returnSize] = (char*)malloc(sizeof(tmp_index+1));
        strncpy(result[*returnSize], tmp_str, tmp_index);
        result[*returnSize][tmp_index] = '\0';
        *returnSize += 1;
        return result;
    }
    if (l > 0)
    {
        tmp_str[tmp_index] = '(';
        result = dfs(l - 1, r, result, returnSize, tmp_str, tmp_index + 1);
    }
    if (r > l)
    {
        tmp_str[tmp_index] = ')';
        result = dfs(l, r - 1, result, returnSize, tmp_str, tmp_index + 1);
    }
    return result;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    if (n == 0)
        return NULL;
    char *tmp_str = (char*)malloc(2*n+1);
    tmp_str[2*n] = '\0';
    char **result = (char**)malloc(4096*sizeof(char**));
    return dfs(n, n, result, returnSize, tmp_str, 0);
}

void showValue(char **ret, int returnSize)
{
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s\n", ret[i]);
    }
}

int main(int argc, char **argv)
{
    printf("%s\n", argv[1]);
    int returnSize = 0;
    char** result = generateParenthesis(atoi(argv[1]), &returnSize);
    showValue(result, returnSize);
}