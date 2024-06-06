#include <stdio.h>
#include <stdlib.h>

int* second_greater_element(int* nums, int numsSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        result[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        int first_greater_found = 0;

        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] > nums[i]) {
                if (!first_greater_found) {
                    first_greater_found = 1;
                } else {
                    result[i] = nums[j];
                    break;
                }
            }
        }
    }

    return result;
}
int main() {
    int nums[] = {3, 1, 5, 2, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int* result = second_greater_element(nums, numsSize);
    printf("Second greater elements:\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", result[i]);
    }
    free(result); 
    return 0;
}
