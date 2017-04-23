/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
Subscribe to see which companies asked this question.
*/

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int total_len = (nums1Size + nums2Size);
    int end_index = total_len / 2;
    int current_number = 0, last_number = 0;
    int num1index = 0, num2index = 0;
    for (int i = 0; i <= end_index - 1; i++)
    {
        if (num1index == nums1Size)
        {
            last_number = nums2[num2index++];
        }
        else if (num2index == nums2Size)
        {
            last_number = nums1[num1index++];
        }
        else
        {
            last_number = (nums1[num1index] < nums2[num2index]) ? nums1[num1index++] : nums2[num2index++];
        }
    }
    if (num1index == nums1Size)
        current_number = nums2[num2index];
    else if (num2index == nums2Size)
        current_number = nums1[num1index];
    else
        current_number = (nums1[num1index] < nums2[num2index]) ? nums1[num1index] : nums2[num2index];
//    printf("current_num %d , last_number %d\n", current_number, last_number);
    if (total_len % 2 == 0)
    {
        return (double)(last_number + current_number) / 2;
    }
    else
    {
        return current_number;
    }
    return 0;
}

int main()
{
    int nums1[] = { };
    int nums2[] = {2,3};
    printf("%f\n", findMedianSortedArrays(nums1, 0, nums2, 2));
    return 0;
}