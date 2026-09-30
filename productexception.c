#include <stdio.h>
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int* result = (int*)malloc(numsSize * sizeof(int));

    *returnSize = numsSize;

    // Step 1: Store products of elements to the left
    result[0] = 1;

    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply by products of elements to the right
    int rightProduct = 1;

    for (int i = numsSize - 1; i >= 0; i--) {

        result[i] = result[i] * rightProduct;

        rightProduct = rightProduct * nums[i];
    }

    return result;
}

int main() {

    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize;

    int* result = productExceptSelf(nums, numsSize, &returnSize);

    printf("Output: [");

    for (int i = 0; i < returnSize; i++) {

        printf("%d", result[i]);

        if (i < returnSize - 1) {
            printf(", ");
        }
    }

    printf("]\n");

    free(result);

    return 0;
}