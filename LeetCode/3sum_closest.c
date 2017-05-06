/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
 {
     return (*(int*)a > *(int*)b);
 }
 
int threeSumClosest(int* nums, int numsSize, int target) {
    if (numsSize < 3)
        return 0;
    unsigned int result = 0xFFFFFFFF;
    int res = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++)
    {
        if (i != 0 && nums[i] == nums[i-1])
            continue;
        int l = i + 1, r = numsSize - 1;
        while (l < r)
        {
            int sum = (nums[l] + nums[r] + nums[i] - target);
            if (result > abs(sum))
            {
                result = abs(sum);
                res = nums[l] + nums[r] + nums[i];
            }
            if (sum == 0)
            {
                return nums[l] + nums[r] + nums[i];
            }
            else if (sum > 0)
            {
                r--;
                while (nums[r] == nums[r+1])
                    r--;
            }
            else if (sum < 0)
            {
                l++;
                while (nums[l] == nums[l-1])
                    l++;
            }
        }
    }
    return res;
}
    
int main()
{
    int s[] = {-1,2,1,-4};
    printf("%d\n", threeSumClosest(s, 4, 1));
    return 0;
}