#include <stdio.h>
#include <stdlib.h>
int count_moves(int* nums, int* target, int n) {
    int* nums_copy = (int*)malloc(n * sizeof(int));
    int* pos = (int*)malloc(n * sizeof(int));
    int moves = 0;
    for (int i = 0; i < n; i++) {
        nums_copy[i] = nums[i];
        pos[nums[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        while (nums_copy[i] != target[i]) {
            int empty_index = pos[0];
            int target_num_index = pos[target[i]];
            int temp = nums_copy[empty_index];
            nums_copy[empty_index] = nums_copy[target_num_index];
            nums_copy[target_num_index] = temp;
            pos[nums_copy[empty_index]] = empty_index;
            pos[nums_copy[target_num_index]] = target_num_index;

            moves++;
        }
    }
    free(nums_copy);
    free(pos);
    return moves;
}
int min_operations_to_sort(int* nums, int numsSize) {
    int n = numsSize;
    int target1[n];
    int target2[n];
    for (int i = 0; i < n; i++) {
        target1[i] = i;
        target2[i] = (i == n - 1) ? 0 : i + 1;
    }

    int moves1 = count_moves(nums, target1, n);
    int moves2 = count_moves(nums, target2, n);
    return (moves1 < moves2) ? moves1 : moves2;
}
int main() {
    int nums[] = {1, 3, 2, 4, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Minimum operations to sort: %d\n", min_operations_to_sort(nums, numsSize));
    return 0;
}
