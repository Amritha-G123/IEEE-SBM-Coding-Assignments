#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *prefix;
    int size;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->size = numsSize;
    obj->prefix = (int *)malloc((numsSize + 1) * sizeof(int));
    obj->prefix[0] = 0;

    for (int i = 0; i < numsSize; i++)
    {
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
    }

    return obj;
}

int numArraySumRange(NumArray *obj, int left, int right)
{
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(NumArray *obj)
{
    free(obj->prefix);
    free(obj);
}

int main()
{
    int nums[] = {-2, 0, 3, -5, 2, -1};
    int n = sizeof(nums) / sizeof(nums[0]);

    // Create the NumArray object
    NumArray *obj = numArrayCreate(nums, n);

    // Call sumRange for each test query
    printf("%d\n", numArraySumRange(obj, 0, 2)); // Prints 1
    printf("%d\n", numArraySumRange(obj, 2, 5)); // Prints -1
    printf("%d\n", numArraySumRange(obj, 0, 5)); // Prints -3

    // Free allocated memory
    numArrayFree(obj);

    return 0;
}