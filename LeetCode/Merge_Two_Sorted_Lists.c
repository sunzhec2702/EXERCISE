/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode result;
    struct ListNode *ptr = &result;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val < l2->val)
        {
            ptr->next = l1;
            l1 = l1->next;
        }
        else
        {
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    ptr->next = (l1 == NULL) ? l2 : l1;
    return result.next;
}

#define SIZE 100
struct ListNode** initValue(int value[SIZE][SIZE], int *nums, int num)
{
    struct ListNode** input = (struct ListNode**)malloc(sizeof(struct ListNode**));
    for (int i = 0; i < num; i++)
    {
        int number = nums[i];
        struct ListNode head_node;
        struct ListNode *ptr = &head_node;
        for (int j = 0; j < number; j++)
        {
            struct ListNode *item = (struct ListNode *)malloc(sizeof(struct ListNode));
            ptr->next = item;
            item->val = value[i][j];
            item->next = NULL;
            ptr = item;
        }
        input[i] = head_node.next;
    }
    return input;
}

void showValue(struct ListNode* ret)
{
    while(ret != NULL)
    {
        printf("%d -> ", ret->val);
        ret = ret->next;
    }
    printf("\n");
}

int main()
{
    int value[SIZE][SIZE] = 
    {
        {1,3,5,7,9},
        {2,4,6,8,10}
    };
    int nums[] = {5,5};
    struct ListNode **input = initValue(value, nums, 2);
    showValue(input[1]);
    struct ListNode *result = mergeTwoLists(input[0], input[1]);
    showValue(result);
    free(input);
    free(result);
    return 0;
}