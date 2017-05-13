/*
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

Subscribe to see which companies asked this question.
*/
#include "utilities.h"

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0 || nums == NULL)
        return 0;
    int index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

int main()
{
    int nums[] = 
    {1,2,2,3,4,5,6,7,8};
    int returnSize = removeElement(nums, sizeof(nums)/sizeof(int), 2);
    showIntArray(nums, returnSize);
    return 0;
}