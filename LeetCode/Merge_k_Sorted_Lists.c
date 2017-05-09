/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Subscribe to see which companies asked this question.
*/

// Actually, we should compare the lists two by two. Then we can skip the first Nlog(N) complex.

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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

int cmd(const void* a, const void* b)
{
    if (*(struct ListNode**)a == NULL)
        return 1;
    else if (*(struct ListNode**)b == NULL)
        return 0;
    return ((*(struct ListNode**)a)->val > (*(struct ListNode**)b)->val);
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
    if (listsSize == 0 || lists == NULL)
        return NULL;
    struct ListNode head;
    struct ListNode *ptr = &head;
    struct ListNode **tmp = (struct ListNode**)malloc(sizeof(struct ListNode*) * listsSize);
    memcpy(tmp, lists, sizeof(struct ListNode*)*listsSize);
    qsort(tmp, listsSize, sizeof(struct ListNode*), cmd);
    while(listsSize > 0)
    {
        ptr->next = tmp[0];
        if (tmp[0] == NULL)
            break;
        tmp[0] = tmp[0]->next;
        ptr = ptr->next;
        qsort(tmp, listsSize, sizeof(struct ListNode*), cmd);
    }
    return head.next;
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

int main()
{
    int value[SIZE][SIZE] = 
    {
        {2,6,10,14,18},
        {1,5,9,13,17,21},
        {3,7,11,15,19,23},
    };
    int nums[] = {5,6,6};
    struct ListNode **input = initValue(value, nums, 3);
    showAllValue(input, 3);
    printf("\n");
    struct ListNode *ret = mergeKLists(input, 3);
    showValue(ret);
    return 0;
}