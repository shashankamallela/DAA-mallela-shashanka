#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int solution(int arr[], int n, int x) {
    int closestSum = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int currentSum = arr[i] + arr[j] + arr[k];
                if (abs(x - closestSum) > abs(x - currentSum)) {
                    closestSum = currentSum;
                }
            }
        }
    }
    return closestSum;
}
int main() {
    int arr[] = { -1, 2, 1, -4 };
    int x = 1;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("The closest sum to %d is %d\n", x, solution(arr, n, x));
    return 0;
}
