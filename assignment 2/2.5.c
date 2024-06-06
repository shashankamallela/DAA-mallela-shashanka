#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int findTriplets(int nums[], int n, int Sum) {
    int i, j, k;
    int found = 0;
    qsort(nums, n, sizeof(int), compare);
    for (i = 0; i < n - 2; i++) {
        j = i + 1;
        k = n - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == Sum) {
                printf("[%d, %d, %d], ", nums[i], nums[j], nums[k]);
                found = 1;
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            } else if (sum > Sum) {
                k--;
            } else {
                j++;
            }
        }

        while (i < n - 2 && nums[i] == nums[i + 1]) i++;
    }
    if (!found) {
        return 0;
    }

    return 1;
}
int main() {
    int nums[] = {12, 3, 6, 1, 6, 9};
    int n = sizeof(nums) / sizeof(nums[0]);
    int Sum = 24;
    if (!findTriplets(nums, n, Sum)) {
        printf("No triplets can be formed.\n");
    }
    return 0;
}
