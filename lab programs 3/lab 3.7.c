#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}
int kadane(int nums[], int numsSize) {
    int current_sum = nums[0];
    int max_sum = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        current_sum = (nums[i] > (current_sum + nums[i])) ? nums[i] : (current_sum + nums[i]);
        max_sum = (max_sum > current_sum) ? max_sum : current_sum;
    }
    
    return max_sum;
}
int maxSubarraySumCircular(int nums[], int numsSize) {
    int total_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }
    int max_kadane = kadane(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = -nums[i];
    }
    
    int max_wraparound = total_sum + kadane(nums, numsSize);

    return (max_kadane > max_wraparound) ? max_kadane : ((max_wraparound != 0) ? max_wraparound : max_kadane);
}

int main() {
    int nums[] = {1, -2, 3, -2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", maxSubarraySumCircular(nums, numsSize));
    return 0;
}
