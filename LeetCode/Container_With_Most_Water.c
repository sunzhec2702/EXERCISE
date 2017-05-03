/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

Subscribe to see which companies asked this question.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define max(a,b) ((a) < (b)) ? (b) : (a)

int maxArea(int* height, int heightSize) {
    int maxArea = 0;
    int last_max_height = 0;
    for (int i = 0; i < heightSize - 1; i++)
    {
        if (height[i] > last_max_height)
        {
            last_max_height = height[i];
            for (int j = heightSize - 1; j > i; j--)
            {
                if (height[j] >= height[i])
                {
                    maxArea = max(maxArea, height[i] * (j - i));
                    break;
                }
                else
                {
                    maxArea = max(maxArea, height[j] * (j - i));
                }
            }
        }
    }
    return maxArea;
}

void initValue(int *value, int number)
{
    srand(time(NULL));
    for (int i = 0; i < number; i++)
    {
        value[i] = rand() % 1024;
    }
}

void showValue(int *value, int number)
{
    for (int i = 0;i < number; i++)
    {
        printf("value[%d] %d\n", i, value[i]);
    }
}

int main(int argc, char **argv)
{
    int number = atoi(argv[1]);
    int *value = (int *)malloc(sizeof(int) * number);
    initValue(value, number);
    showValue(value, number);
    printf("Max Area is %d\n", maxArea(value, number));
    return 0;
}