#include <stdio.h>

int jump(int nums[], int numsSize)
{
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;

    for (int i = 0; i < numsSize - 1; i++)
    {
        // Find the farthest position we can reach
        if (i + nums[i] > farthest)
        {
            farthest = i + nums[i];
        }

        // Current jump has reached its end
        if (i == currentEnd)
        {
            jumps++;
            currentEnd = farthest;
        }
    }

    return jumps;
}

int main()
{
    int nums[] = {2, 3, 1, 1, 4};

    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = jump(nums, numsSize);

    printf("Minimum number of jumps = %d\n", result);

    return 0;
}