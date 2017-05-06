/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
Subscribe to see which companies asked this question.

*/

#include <stdio.h>
#include <stdlib.h>

void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x)
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x)
                i++;
            if (i<j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}

 #define MALLOC_NUM 20240
 
 int cmp(const void *a, const void *b)
 {
     return (*(int*)a > *(int*)b);
 }
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3)
        return NULL;
    //int **result = NULL;
    int **result = (int**)malloc(MALLOC_NUM * sizeof(int*));
    //quick_sort(nums, 0, numsSize - 1);
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++)
    {
        if (i != 0 && nums[i] == nums[i-1])
            continue;
        int l = i + 1, r = numsSize - 1;
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == (-1 * nums[i]))
            {
                //result = (int**)realloc(result, (*returnSize + 1) * sizeof(int*));
                result[*returnSize] = (int*)malloc(3*sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[l];
                result[*returnSize][2] = nums[r];
                *returnSize += 1;
                l++;r--;
                while (nums[l] == nums[l-1])
                    l++;
                while (nums[r] == nums[r+1])
                    r--;
            }
            else if (sum > (-1 * nums[i]))
            {
                r--;
                while (nums[r] == nums[r+1])
                    r--;
            }
            else if (sum < (-1 * nums[i]))
            {
                l++;
                while (nums[l] == nums[l-1])
                    l++;
            }
        }
    }
    return result;
}

void showValue(int **value, int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < 3;j++)
        {
            printf("%d ", value[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int s[] = {-1, 0, 1, 2, -1, -4};
    int returnSize = 0;
    int** result = threeSum(s, 6, &returnSize);
    showValue(result, returnSize);
    return 0;
}