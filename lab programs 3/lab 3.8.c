#include <stdio.h>

#define MOD 1000000007

int max(int a, int b) {
    return (a > b) ? a : b;
}
int maxNonAdjacentSum(int nums[], int numsSize) {
    int incl = 0, excl = 0;
    for (int i = 0; i < numsSize; i++) {
        int new_excl = max(excl, incl);
        incl = excl + nums[i];
        excl = new_excl;
    }
    return max(incl, excl);
}

int maxSumAfterQueries(int nums[], int numsSize, int queries[][2], int queriesSize) {
    int total_sum = 0;
    for (int i = 0; i < queriesSize; i++) {
        int pos = queries[i][0];
        int xi = queries[i][1];
        nums[pos] = xi;
        total_sum += maxNonAdjacentSum(nums, numsSize);
    }
    return total_sum % MOD;
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int queries[][2] = {{0, 2}, {1, 3}, {2, 4}};
    int queriesSize = sizeof(queries) / sizeof(queries[0]);
    printf("%d\n", maxSumAfterQueries(nums, numsSize, queries, queriesSize));
    return 0;
}
