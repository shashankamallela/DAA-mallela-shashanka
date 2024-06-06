#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Solution {
    bool* (*kidsWithCandies)(struct Solution*, int*, int, int, int*);
};

bool* kidsWithCandies(struct Solution* this, int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize;
    bool* result = (bool*)malloc(candiesSize * sizeof(bool));
    int maxCandies = candies[0];
    
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > maxCandies) {
            maxCandies = candies[i];
        }
    }
    
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= maxCandies) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }
    
    return result;
}

int main() {
    struct Solution solution;
    solution.kidsWithCandies = kidsWithCandies;
    
    int candies[] = {2, 3, 5, 1, 3};
    int candiesSize = sizeof(candies) / sizeof(candies[0]);
    int extraCandies = 3;
    int returnSize;
    
    bool* result = solution.kidsWithCandies(&solution, candies, candiesSize, extraCandies, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i] ? "true" : "false");
    }
    
    free(result);
    return 0;
}



