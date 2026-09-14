#include <stdio.h>
double findMaxAverage(int *nums, int numsSize, int k)
{
    int sum = 0;

    // Find sum of first window
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    int maxSum = sum;

    // Slide window
    for (int i = k; i < numsSize; i++)
    {
        sum += nums[i] - nums[i - k];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }

    return (double)maxSum / k;
}
int main()
{
    int nums[] = {1, 12, -5, -6, 50, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 4;

    double result = findMaxAverage(nums, numsSize, k);
    printf("Max average: %f\n", result);

    return 0;
}