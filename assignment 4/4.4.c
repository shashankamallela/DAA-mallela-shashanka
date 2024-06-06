#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int min_addition_to_make_beautiful(int n, int target) {
    if (sum_of_digits(n) <= target) {
        return 0;
    }
    int x = 0;
    int increment = 1;
    while (sum_of_digits(n + x) > target) {
        int next_increment = increment - (n % increment);
        x += next_increment;
        n += next_increment;
        increment *= 10;
    }

    return x;
}
int main() {
    int n = 123;
    int target = 6;
    printf("Minimum addition to make %d beautiful: %d\n", n, min_addition_to_make_beautiful(n, target));
    return 0;
}
