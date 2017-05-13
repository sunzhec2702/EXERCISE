#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

#define MAX_SIZE 1024

extern struct ListNode** initLists(int value[MAX_SIZE][MAX_SIZE], int *nums, int num);
extern void showListsValue(struct ListNode **ret, int num);
extern void showListValue(struct ListNode *ret);
extern void showIntArray(int *array, int number);


#endif