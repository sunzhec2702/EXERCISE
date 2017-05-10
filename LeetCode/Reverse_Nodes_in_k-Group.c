/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};


void showValue(struct ListNode *ret)
{
    while (ret != NULL)
    {
        printf("%d -> ", ret->val);
        ret = ret->next;
    }
    printf("NULL\n");
}

void showAllValue(struct ListNode **ret, int num)
{
    for (int i = 0; i < num; i++)
    {
        showValue(ret[i]);
    }
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

struct ListNode *revertK(struct ListNode *head, int k)
{
    if (head == NULL || k == 1)
    {
        return head;
    }
    struct ListNode *ptr = head, *last = NULL, *first = head;
    for (int i = 0; i < k; i++)
    {
        if (ptr == NULL)
        {
            return (revertK(last, i));
        }
        struct ListNode *next = ptr->next;
        ptr->next = last;
        last = ptr;
        ptr = next;
    }
    first->next = ptr;
    return last;
}

struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
    if (k == 1 || head == NULL)
        return head;
    struct ListNode ret;
    struct ListNode *ret_ptr = &ret, *ptr = head;
    while (ptr != NULL)
    {
        struct ListNode *tmp =revertK(ptr, k);
        ret_ptr->next = tmp;
        ret_ptr = ptr;
        for (int i = 0; i < k; i++)
        {
            if (tmp == NULL)
                return ret.next;
            tmp = tmp->next;
        }
        ptr = tmp;
    }
    return ret.next;
}

int main()
{
    int value[SIZE][SIZE] = 
    {
        {1,2,3,4,5,6,7,8,9}        
    };
    int nums[] = {9};
    struct ListNode **input = initValue(value, nums, 1);
    showValue(input[0]);
    showValue(reverseKGroup(input[0], 3));
    return 0;
}