#include <stdio.h>
int recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return (recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2));
    }
}

int main() {
    int n_terms = 10;
    if (n_terms <= 0) {
        printf("Invalid input! Please input a positive value\n");
    } else {
        printf("Fibonacci series:\n");
        for (int i = 0; i < n_terms; i++) {
            printf("%d ", recursive_fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
