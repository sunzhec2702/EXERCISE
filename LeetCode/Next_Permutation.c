/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
Subscribe to see which companies asked this question.

就是找到比当前数字大的最小值。如果已经是最大值了，就找最小值，循环。

*/

#include "utilities.h"
/*
这道题主要需要分析数字规律，想清楚题目要求什么。
第一直观反应是需要从后往前找，找到比当前数字更小的一个，交换即可。但是实际上，除了交换，还需要将交换之后的逆序排列，保证后面的排序是最小的。
所以，这道题的思路如下。
1.从后往前找，两个两个比较。如果每一个数字都比前面的数字小，说明这组数已经是最大值了，直接进行逆序排列。
2.找到一个数字i比前面的数字j大，说明这个数字i以及这个数字i往后的都是降序排列了。在这个基础上，从后往前找一个比j还小的数字和j交换，然后在将i往后的数字降序排列即可。
*/

void swap(int *nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void reverse(int *nums, int start, int end)
{
    if (start >= end)
        return;
    for (int i = start; i <= (start + end)/2; i++) {
        swap(nums, i, end + start - i);
    }
    return;
}

void nextPermutation(int* nums, int numsSize)
{
    if (numsSize <= 0)
        return;
    int index = numsSize - 1;
    //判断是不是直接就OK。
    while(index > 0) {
        if (nums[index] > nums[index-1]) {
            break;
        }
        index--;
    }
    //如果已经是最大了，就直接reverse就好。
    if (index == 0) {
        reverse(nums, 0, numsSize - 1);
        return;
    }
    //通常的情况，判断一下。
    int findIndex = numsSize - 1;
    int target = nums[index - 1];
    printf("findIndex = %d, target = %d\n", findIndex, target);
    while(findIndex >= index) {
        if (nums[findIndex] > target) {
            printf("Found one, nums[%d] %d\n", findIndex, nums[findIndex]);
            swap(nums, findIndex, index - 1);
            reverse(nums, index, numsSize - 1);
            return;
        }
        findIndex--;
    }
    return;
}

#define NUMBER 6
int main()
{
    int input[] = {2,2,0,4,3,1};
    for (int i = 0; i < NUMBER - 1; i++) {
        printf("%d -> ", input[i]);
    }
    printf("%d\n", input[NUMBER-1]);
    nextPermutation(input, NUMBER);
    for (int i = 0; i < NUMBER - 1; i++) {
        printf("%d -> ", input[i]);
    }
    printf("%d\n", input[NUMBER-1]);
    return 0;
}
