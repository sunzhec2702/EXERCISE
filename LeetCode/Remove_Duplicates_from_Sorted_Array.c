/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question.
*/
#include "utilities.h"

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2 || nums == NULL)
        return numsSize;
    int index = 0, count = 0, last = nums[0];
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == last)
            count++;
        else
        {
            nums[index++] = last;
            last = nums[i];
            count = 0;
        }
    }
    nums[index++] = last;
    return index;
}

int main()
{
    int nums[] = 
    {1,2,2,3,4,5,6,7,8};
    int returnSize = removeDuplicates(nums, sizeof(nums)/sizeof(int));
    showIntArray(nums, returnSize);
    return 0;
}