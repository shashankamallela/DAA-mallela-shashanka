#include <stdio.h>
int maxSubArray(int nums[], int numsSize) {
    int current_sum = nums[0];
    int max_sum = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        current_sum = (nums[i] > (current_sum + nums[i])) ? nums[i] : (current_sum + nums[i]);
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }
    
    return max_sum;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", maxSubArray(nums, numsSize));
    return 0;
}
