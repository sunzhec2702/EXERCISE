/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Subscribe to see which companies asked this question.
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "utilities.h"

struct ListNode *swapPairs(struct ListNode *head)
{
    if (head == NULL)
        return NULL;
    struct ListNode ret, *ptr = head;
    struct ListNode *ret_ptr = &ret;
    ret_ptr->next = head;
    while (ptr != NULL)
    {
        struct ListNode *next = ptr->next;
        if (next == NULL)
            break;
        else
        {
            ret_ptr->next = next;
            ptr->next = next->next;
            next->next = ptr;
            ret_ptr = ptr;
            ptr = ptr->next;
        }
    }
    return ret.next;
}

int main()
{
    int value[MAX_SIZE][MAX_SIZE] =
        {
            {2, 6, 10, 14, 18},
        };
    int nums[] = {5};
    struct ListNode **input = initValue(value, nums, 1);
    showValue(input[0]);
    showValue(swapPairs(input[0]));
    return 0;
}