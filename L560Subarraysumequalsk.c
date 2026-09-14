#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int sum;
    int count;
} SumFreq;

int subarraySum(int *nums, int numsSize, int k)
{

    SumFreq *freq = (SumFreq *)malloc((numsSize + 1) * sizeof(SumFreq));
    int size = 0;

    // Initialize with prefix sum 0 occurring 1 time
    freq[0].sum = 0;
    freq[0].count = 1;
    size++;

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++)
    {
        prefixSum += nums[i];
        int target = prefixSum - k;

        for (int j = 0; j < size; j++)
        {
            if (freq[j].sum == target)
            {
                count += freq[j].count;
                break;
            }
        }

        int found = 0;
        for (int j = 0; j < size; j++)
        {
            if (freq[j].sum == prefixSum)
            {
                freq[j].count++;
                found = 1;
                break;
            }
        }

        // Add new prefixSum if not found
        if (!found)
        {
            freq[size].sum = prefixSum;
            freq[size].count = 1;
            size++;
        }
    }

    free(freq);
    return count;
}
int main()
{
    int nums1[] = {1, 1, 1};
    int k1 = 2;
    int n1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1: int nums1[] = {1, 1, 1}int k1 = 2\nOutput: %d\n", subarraySum(nums1, n1, k1));

    int nums2[] = {1, 2, 3};
    int k2 = 3;
    int n2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2:int nums2[] = {1, 2, 3};int k2 = 3;\nOutput: %d\n", subarraySum(nums2, n2, k2));

    return 0;
}