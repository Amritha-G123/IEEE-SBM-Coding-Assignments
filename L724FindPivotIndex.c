#include <stdio.h>

int pivotIndex(int *nums, int numsSize)
{
    int totalSum = 0;
    int leftSum = 0;
    int i;

    // Calculate the total sum
    for (i = 0; i < numsSize; i++)
    {
        totalSum = totalSum + nums[i];
    }

    // Check every index
    for (i = 0; i < numsSize; i++)
    {
        int rightSum = totalSum - leftSum - nums[i];

        if (leftSum == rightSum)
        {
            return i;
        }

        leftSum = leftSum + nums[i];
    }

    return -1;
}

int main()
{
    // Example 1
    int nums1[] = {1, 7, 3, 6, 5, 6};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Example 1:nums1[] = {1, 7, 3, 6, 5, 6};\n Expected = 3, Output = %d\n", pivotIndex(nums1, size1));

    // Example 2
    int nums2[] = {1, 2, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Example 2: nums2[] = {1, 2, 3};\nExpected = -1, Output = %d\n", pivotIndex(nums2, size2));

    // Example 3
    int nums3[] = {2, 1, -1};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Example 3: nums3[] = {2, 1, -1};\nExpected = 0, Output = %d\n", pivotIndex(nums3, size3));

    return 0;
}