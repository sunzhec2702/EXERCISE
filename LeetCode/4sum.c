/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>

#define MALLOC_NUM 20240
 
 int cmp(const void *a, const void *b)
 {
     return (*(int*)a > *(int*)b);
 }
 
int** threeSum(int* nums, int numsSize, int* returnSize, int target) {
    if (numsSize < 3)
        return NULL;
    int **result = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        if (i != 0 && nums[i] == nums[i-1])
            continue;
        int l = i + 1, r = numsSize - 1;
        while (l < r)
        {
            int sum = nums[l] + nums[r] + nums[i];
            if (sum == target)
            {
                result = (int**)realloc(result, (*returnSize + 1) * sizeof(int*));
                result[*returnSize] = (int*)malloc(4*sizeof(int));
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
            else if (sum > target)
            {
                r--;
                while (nums[r] == nums[r+1])
                    r--;
            }
            else if (sum < target)
            {
                l++;
                while (nums[l] == nums[l-1])
                    l++;
            }
        }
    }
    return result;
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if (numsSize < 4)
    {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int **result = (int**)malloc(sizeof(int*) * MALLOC_NUM);
    for (int i = 0; i < numsSize - 3; i++)
    {
        if (i != 0 && nums[i] == nums[i-1])
            continue;
        int retSize = 0;
        int **ret = threeSum(&nums[i+1], numsSize - i - 1, &retSize, target - nums[i]);
        if (ret != NULL && retSize != 0)
        {
            for (int j = 0; j < retSize; j++)
            {
                result[*returnSize+j] = ret[j];
                result[*returnSize+j][3] = nums[i];
            }
            *returnSize += retSize;
        }
    }
    return result;
}

void showValue(int **value, int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < 4;j++)
        {
            printf("%d ", value[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int s[] = {1, 0, -1, 0, -2, 2};
    int returnSize = 0;
    int** result = fourSum(s, 6, 0, &returnSize);
    showValue(result, returnSize);
    return 0;
}