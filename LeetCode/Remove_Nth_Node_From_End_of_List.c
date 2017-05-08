/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

Subscribe to see which companies asked this question.
*/

#include <stdio.h>
#include <stdlib.h>

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

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode *front = head, *end = head, *last = head;
    if (head == NULL)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        end = end->next;
    }
    if (end == NULL)
        return head->next;
    while (end != NULL)
    {
        last = front;
        front = front->next;
        end = end->next;
    }
    last->next = front->next;
    return head;
}

struct ListNode* initValue(char **number, int size)
{
    struct ListNode head;
    struct ListNode* ptr = &head;
    for (int i = 0; i < size; i++)
    {
        struct ListNode* item = (struct ListNode*)malloc(sizeof(struct ListNode));
        ptr->next = item;
        item->val = atoi(number[i]);
        printf("%d -> ", item->val);
        item->next = NULL;
        ptr = item;
    }
    printf("\n");
    return head.next;
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

int main(int argc, char** argv)
{
    //int num[16] = {1,2,4,5,6,7,8,9,0,6,54,3,232,32,32,12};
    printf("remove %dth item from\n", atoi(argv[1]));
    struct ListNode* input = initValue(&argv[2], argc - 2);
    struct ListNode* ret = removeNthFromEnd(input, atoi(argv[1]));
    showValue(ret);
    return 0;
}