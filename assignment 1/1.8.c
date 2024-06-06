#include <stdio.h>
#include <stdlib.h>

int containsZero(int num) {
    while (num > 0) {
        if (num % 10 == 0) {
            return 1; 
        }
        num /= 10;
    }
    return 0; 
}
int* getNoZeroIntegers(int n) {
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int A = 1; A < n; ++A) {
        int B = n - A;
        if (!containsZero(A) && !containsZero(B)) {
            result[0] = A;
            result[1] = B;
            return result;
        }
    }
    return NULL;
}

int main() {
    int n = 11;
    int* result = getNoZeroIntegers(n);
    if (result != NULL) {
        printf("No zero integers: %d, %d\n", result[0], result[1]);
        free(result);
    } else {
        printf("No valid pair found.\n");
    }
    return 0;
}
