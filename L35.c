#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main()
{
    int nums[] = {1, 3, 5, 6};
    int numsSize = 4;
    int target = 2;

    int answer = searchInsert(nums, numsSize, target);

    printf("Insert position = %d\n", answer);

    return 0;
}