#include "utilities.h"

void showListValue(struct ListNode *ret)
{
    while (ret != NULL)
    {
        printf("%d -> ", ret->val);
        ret = ret->next;
    }
    printf("NULL\n");
}

void showListsValue(struct ListNode **ret, int num)
{
    for (int i = 0; i < num; i++)
    {
        showListValue(ret[i]);
    }
}

struct ListNode** initLists(int value[MAX_SIZE][MAX_SIZE], int *nums, int num)
{
    struct ListNode** input = (struct ListNode**)malloc(sizeof(struct ListNode**));
    for (int i = 0; i < num; i++)
    {
        int number = nums[i];
        struct ListNode head_node;
        struct ListNode *ptr = &head_node;
        printf("number is %d\n", number);
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

void showIntArray(int *array, int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}


/*
int main()
{
    int value[MAX_SIZE][MAX_SIZE] = 
    {
        {2,6,10,14,18},
        {1,5,9,13,17,21},
        {3,7,11,15,19,23},
    };
    int nums[] = {5,6,6};
    struct ListNode **input = initValue(value, nums, 3);
    showAllValue(input, 3);
    return 0;
}
*/