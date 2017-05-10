#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

#define MAX_SIZE 1024

extern struct ListNode** initValue(int value[MAX_SIZE][MAX_SIZE], int *nums, int num);
extern void showAllValue(struct ListNode **ret, int num);
extern void showValue(struct ListNode *ret);


#endif